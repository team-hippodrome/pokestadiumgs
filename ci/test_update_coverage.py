import tempfile
import sys
import unittest
import xml.etree.ElementTree as ET
from pathlib import Path
from unittest.mock import patch

import update_coverage as coverage


class InstructionCoverageTests(unittest.TestCase):
    def write_function(self, root, name, count):
        path = root / "test" / f"{name}.s"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("/* 0000 80000000 00000000 */ nop\n" * count)

    def test_bucket_boundaries_and_totals(self):
        counts = [1, 99, 100, 199, 200, 299, 300, 399, 400, 499,
                  500, 699, 700, 999, 1000, 1499, 1500, 1999, 2000]
        totals = [3] * 11
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for i, count in enumerate(counts):
                self.write_function(root, f"f{i}", count)
            buckets = coverage.instruction_buckets(
                {"src/test.c": {f"f{i}" for i in range(len(counts))}}, totals, root)
        self.assertEqual(buckets[:9], [[1, 2]] * 9)
        self.assertEqual(buckets[9:], [[2, 1], [3, 0]])
        self.assertEqual(sum(sum(pair) for pair in buckets), sum(totals))

    def test_baseline_totals_are_read_from_existing_table(self):
        buckets = [[3, 2]] * 11
        snapshot = coverage.CoverageSnapshot(33, 55, 60, {}, buckets)
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "COVERAGE.md"
            path.write_text(coverage.render(snapshot, {}), encoding="utf-8")
            with patch.object(coverage, "BASELINE_TOTAL", 55):
                self.assertEqual(coverage.baseline_bucket_totals(path), [5] * 11)
            with self.assertRaisesRegex(ValueError, "baseline coverage table"):
                coverage.baseline_bucket_totals(path)

    def test_missing_assembly_fails_instead_of_inventing_size(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaisesRegex(ValueError, "missing original assembly"):
                coverage.instruction_buckets({"src/test.c": {"absent"}}, [1] * 11, Path(directory))

    def test_directives_are_excluded_and_bucket_overflow_fails(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write_function(root, "f", 2)
            with (root / "test/f.s").open("a") as output:
                output.write("/* 0000 80000000 00000000 */ .word 0\n")
            buckets = coverage.instruction_buckets({"src/test.c": {"f"}}, [1] * 11, root)
            self.assertEqual(buckets[0], [0, 1])
            with self.assertRaisesRegex(ValueError, "exceeds its baseline total"):
                coverage.instruction_buckets({"src/test.c": {"f"}}, [0] * 11, root)

    def test_svg_is_valid_deterministic_and_contains_counts(self):
        buckets = [[100, 25]] + [[0, 0] for _ in range(10)]
        graph = coverage.render_graph(buckets)
        ET.fromstring(graph)
        self.assertEqual(graph, coverage.render_graph(buckets))
        self.assertIn("100 C upstream; 25 open; 125 total", graph)

    def test_check_detects_missing_or_stale_graph(self):
        buckets = [[1, 0]] + [[0, 0] for _ in range(10)]
        snapshot = coverage.CoverageSnapshot(1, 1, 100.0, {}, buckets)
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            argv = ["update_coverage.py", "--repo-root", str(root)]
            with patch.object(coverage, "snapshot", return_value=snapshot):
                with patch.object(sys, "argv", argv):
                    self.assertEqual(coverage.main(), 0)
                with patch.object(sys, "argv", argv + ["--check"]):
                    self.assertEqual(coverage.main(), 0)
                    graph = root / "docs/coverage.svg"
                    graph.write_text("stale")
                    self.assertEqual(coverage.main(), 1)
                    graph.unlink()
                    self.assertEqual(coverage.main(), 1)


if __name__ == "__main__":
    unittest.main()
