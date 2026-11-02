#!/usr/bin/env python3
"""Import original instruction counts from a baseline US splat disassembly.

This is a one-time baseline maintenance tool, not part of the hourly refresh.
Use the source/symbol snapshot named by baseline_revision in the manifest,
split the US ROM with splat --disassemble-all, then pass asm/us/nonmatchings
as --asm-root. Only counts and provenance are retained in the manifest.
"""
import argparse
import json
import re
from pathlib import Path


INSTRUCTION = re.compile(
    r"^\s*/\*\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+[0-9A-Fa-f]{8}\s+\*/\s+[A-Za-z]",
    re.MULTILINE,
)


def import_sizes(manifest: dict, asm_root: Path) -> dict:
    for row in manifest["functions"]:
        source, name, _, _ = row
        relative = Path(source).relative_to("src").with_suffix("")
        path = asm_root / relative / f"{name}.s"
        row[2] = (len(INSTRUCTION.findall(path.read_text(encoding="utf-8"))) or None
                  if path.exists() else None)
    manifest["method"] = (
        "Instruction-comment lines in baseline US splat --disassemble-all output; "
        "assembly directives, rodata, and labels are excluded. Missing bodies have null counts."
    )
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--asm-root", type=Path, required=True)
    parser.add_argument("--manifest", type=Path, default=Path(__file__).with_name("coverage_functions.json"))
    args = parser.parse_args()
    if not args.asm_root.is_dir():
        parser.error("--asm-root must be a generated nonmatchings directory")
    manifest = import_sizes(json.loads(args.manifest.read_text(encoding="utf-8")), args.asm_root)
    # Keep one function per line for baseline reviews.
    rows = ",\n".join("    " + json.dumps(row) for row in manifest.pop("functions"))
    header = json.dumps(manifest, indent=2)[:-2]
    args.manifest.write_text(header + ',\n  "functions": [\n' + rows + '\n  ]\n}\n', encoding="utf-8")


if __name__ == "__main__":
    main()
