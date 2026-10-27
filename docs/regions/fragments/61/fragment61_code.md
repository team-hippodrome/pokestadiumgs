# Fragment 61 camera callback

## Accepted: `func_86B00020`, 2026-10-20

The 208-byte callback sets the perspective and places the camera at
`(0, sin(angle) * radius + 400 + centerY, cos(angle) * radius)`, looking
toward `(0, centerY, 0)`. `D_86B0D16C` supplies the angle, `D_86B0D168`
the radius, `D_86B0D170` the center height and `D_86B0D174` the field of
view. When `D_86B17EAC` is zero, the original `func_87C037C0` camera call
with `D_86B17E2C` is preserved.

The actual six-float/`u16` helper signature and the consumed `u16 roll = 0`
value reproduce the original instructions and 56-byte frame without the old
word rewrite or unused padding. The normal runner accepts the callback with
`link_verified: true` and a full-ROM gate; do not candidate-probe it again.

Shared evidence and source-shape limits are recorded in
`docs/regions/fragments/60/fragment60_code.md`. Independent retail links
cover every one of this module's 63 function extents and all 53,568 text
bytes. All frozen-stage, whole-module, collateral, public compiler path,
blank-line, provenance, syntax, regression and final normal-ROM checks pass.
Other owners in this file remain outside this correction.


## func_86B09480: counter-driven node update

The 172-byte owner (43 instructions, 24-byte frame) obtains its current node
from `D_87F119DC`. It reads the signed counter at offset 28 once. After
counter 10 it calculates `(counter - 10) * D_86B0E018 + 2.0` in double
precision, converts to float, and writes offsets 92, 88 and 84, reloading
the global node pointer between stores. It also subtracts 12 from the word
at `D_86B17A78 + 148`. After counter 30 it releases the current node through
`func_87F026E8`. The field meanings beyond these operations remain unknown.
The existing double constant is 0.06 in the US retail data; no new storage
or rounded replacement literal is introduced.

`func_86B0952C` registers this no-argument callback with `func_87F025B8`,
initializes its counter to zero and the three float fields to 2.0.
`func_87F0277C` invokes the registered callback and increments the current
node's counter. `func_87F026E8` takes the state and node pointers, clears
the active flag, unlinks the node and decrements the state's active count.
The three repeated declarations of that helper and `D_87F119D8` in this
translation unit now describe their actual pointer arguments and storage;
existing caller bodies remain unchanged.

//@src/fragments/61/fragment61_code.c
//@src/fragments/64/fragment64_324FB0.c

Validation uses master `796f1ce5815fdff0a176bbddedda7ea01b412733` plus
this source change. The first C recipe reproduces all 43 original words,
including the global reloads, floating-point operations and counter tests.
The raw retail span `0x2FC3D0..0x2FC47C` also compares exactly.

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/61/fragment61_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The default host syntax check, forced translation-unit rebuild and full US
link pass with `build/pokestadiumgs-us.z64: OK`. The complete ROM has MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` and matches retail byte-for-byte,
including every existing caller affected by the declaration corrections.
