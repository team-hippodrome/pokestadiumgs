import tempfile
import sys
import unittest
import xml.etree.ElementTree as ET
from pathlib import Path
from unittest.mock import patch

import update_coverage as coverage
from import_coverage_sizes import import_sizes


class InstructionCoverageTests(unittest.TestCase):
    def buckets(self, rows, owners=None, symbols=""):
        with patch.object(coverage, "BASELINE_TOTAL", len(rows)):
            return coverage.instruction_buckets(owners or {}, rows, symbols)

    def test_bucket_boundaries_unknown_and_totals(self):
        counts = [1, 99, 100, 199, 200, 299, 300, 399, 400, 499,
                  500, 699, 700, 999, 1000, 1499, 1500, 1999, 2000, None]
        rows = [["src/test.c", f"f{i}", count, i] for i, count in enumerate(counts)]
        owners = {"src/test.c": {"f1", "f18", "f19"}}
        buckets = self.buckets(rows, owners)
        self.assertEqual(buckets[0], [1, 1])
        self.assertEqual(buckets[9:], [[0, 1], [0, 1]])
        self.assertEqual(sum(x[0] for x in buckets), len(rows) - 3)
        self.assertEqual(sum(x[1] for x in buckets), 3)
        self.assertTrue(all(pair == [2, 0] for pair in buckets[1:9]))

    def test_renamed_owner_uses_original_address_and_size(self):
        rows = [["src/old.c", "func_80001000", 125, 2147487744]]
        buckets = self.buckets(rows, {"src/new.c": {"DrawPanel"}},
                               "DrawPanel = 0x80001000; // type:func\n")
        self.assertEqual(buckets[1], [0, 1])

    def test_missing_owner_fails_instead_of_inventing_size(self):
        with self.assertRaisesRegex(ValueError, "missing from instruction baseline"):
            self.buckets([["src/test.c", "f", 5, 1]], {"src/test.c": {"unknown"}})

    def test_disassembly_import_excludes_directives_and_rodata(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "test").mkdir()
            (root / "test/f.s").write_text(
                ".section .rodata\n/* 0000 80000000 00000000 */ .word 0\n"
                ".section .text\nglabel f\n"
                "/* 0004 80000004 03E00008 */ jr $ra\n"
                "/* 0008 80000008 00000000 */  nop\n")
            manifest = {"functions": [["src/test.c", "f", None, 1],
                                      ["src/test.c", "absent", None, 2]]}
            result = import_sizes(manifest, root)
            self.assertEqual([row[2] for row in result["functions"]], [2, None])

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
