#!/usr/bin/env bash
# Generate reports from a fresh US disassembly in the local ROM-equipped image.
# The checkout is read-only; only the three report files leave the container.
set -euo pipefail

if [ "$#" -ne 2 ]; then
    echo 'usage: generate-coverage.sh <checkout-dir> <output-dir>' >&2
    exit 2
fi
checkout_dir="$(cd "$1" && pwd)"
mkdir -p "$2"
output_dir="$(cd "$2" && pwd)"
image="${GS_DECOMP_AGENT_IMAGE:-gs-decomp-agent-pokestadiumgs:latest}"

docker run --rm --platform linux/amd64 \
    --network none --cap-drop=ALL --security-opt=no-new-privileges \
    --pids-limit=2048 \
    -v "$checkout_dir:/src:ro" -v "$output_dir:/out:rw" \
    --entrypoint bash "$image" -c '
set -euo pipefail
mkdir -p /tmp/coverage/baseroms/us
cp -a /src/src /src/yamls /src/linker_scripts /src/tools /tmp/coverage/
ln -s /work/baseroms/us/baserom.z64 /tmp/coverage/baseroms/us/baserom.z64
cd /tmp/coverage
cat yamls/us/header.yaml yamls/us/rom.yaml > pokestadiumgs-us.yaml
/work/.venv/bin/python3 -m splat split pokestadiumgs-us.yaml --modes code --disassemble-all
python3 /src/ci/update_coverage.py --repo-root /src \
    --baseline /src/COVERAGE.md --asm-root /tmp/coverage/asm/us/nonmatchings \
    --output /out/COVERAGE.md
python3 /src/ci/update_coverage.py --repo-root /src \
    --baseline /src/COVERAGE.md --asm-root /tmp/coverage/asm/us/nonmatchings \
    --output /out/COVERAGE.md --check
python3 /src/ci/update_undocumented.py --repo-root /src --output /out/UNDOCUMENTED.md
'
