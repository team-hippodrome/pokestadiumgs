# Opcode rewrite cleanup

Baseline: `7d0511c4829cce1912c2a5ced28734f343ebbc66` (2026-11-02). The US source contains
65 affected functions across 45 files, with 794 directives from the seven
families below. One directive patches `.rodata` for `func_8F401C30` rather
than naming a function directly.

| Directive | Baseline occurrences |
| --- | ---: |
| `REWRITE_FUNCTION_HEX` | 27 |
| `REWRITE_FUNCTION_RELOC_TARGET` | 558 |
| `SWAP_FUNCTION_WORDS` | 4 |
| `REWRITE_FUNCTION_WORD` | 159 |
| `COALESCE_AT_LUI` | 21 |
| `REWRITE_SECTION_WORD` | 1 |
| `REWRITE_FUNCTION_RELOC` | 24 |

The native baseline passes the normal host syntax checks and full-ROM
comparison. Each source file was also compiled unchanged and with 20 leading
blank lines, checking complete allocated bytes/layout, defined function
extents and semantic relocations. Each function was then compiled with only
its own listed directives removed. All 65 functions differed; the separate
section-patch removal also differed. No baseline removal was installed.

A replacement must preserve behavior and compile to the retail instructions
through the stock build. Removing a directive, obtaining a normalized score,
or reverting a function to assembly does not establish a proper C match.

## Completed replacements

- `func_87E07DD0`: decode the high status bit as an unsigned shift, matching
  its neighboring count/search helpers. This removes two word rewrites while
  preserving the complete module. Normal and leading-blank controls, the
  normal host syntax check, and the full retail ROM comparison pass. See
  [the fragment 63 evidence](regions/fragments/63/fragment63_30B540.md).

- `func_82001A78`: assign the packed status or fallback value in all three
  branches and use one return. Stock IDO now emits the original zero-result
  flow, removing two more word rewrites. Complete-module controls, normal
  host syntax and full retail ROM comparison pass. See
  [the fragment 16 evidence](regions/fragments/16/fragment16_code.md).

- `func_87C03B10`: keep the float dot product in a double denominator and
  divide the float numerator by that value. Stock IDO now emits all 80 retail
  bytes without six word rewrites or the instruction swap. Complete-module
  normal/blank controls, normal host syntax and full retail ROM comparison
  pass. See [the fragment 48 evidence](regions/fragments/48/fragment48_2597B0.md).

- `func_83F001A8`: define its real timestamp as C BSS and separate the
  loader's relocation metadata from runtime storage. Stock IDO emits the
  shared address load without `COALESCE_AT_LUI`. The metadata bytes and runtime
  fixups are preserved; module controls, host syntax and the full retail ROM
  comparison pass. See [the fragment 15 evidence](regions/fragments/15/fragment15_code.md).

- `func_81700B8C`: use the actual text-pointer/font-measurement contract
  and the 36-byte entry layout. Unsigned address calculation precedes the
  existing guards; entry accesses remain guarded. Stock IDO emits all 128
  retail bytes without three word rewrites. Complete-module controls, host
  syntax and the full retail ROM comparison pass. See
  [the fragment 18 evidence](regions/fragments/18/fragment18_code.md).

- `func_87F025B8`: assign the previous link directly before clearing the
  next link when appending a newly allocated pool item. Removing the tail
  temporary lets stock IDO emit all 204 retail bytes without four word
  rewrites. Complete-module controls, host syntax and the full retail ROM
  comparison pass. See [the fragment 64 evidence](regions/fragments/64/fragment64_324FB0.md).

- `func_8AC06D8C`: own its actual lookup-failure record in C and use the
  existing NOLOAD data-placement mechanism at its original runtime address.
  Stock IDO shares the address load without `COALESCE_AT_LUI`. Normal module
  controls, host syntax and the full retail ROM gate pass; existing pool
  statics and legacy addresses remain exact. See
  [the fragment 43 evidence](regions/fragments/43/fragment43_1E5A10.md).

- `func_82204744`, `func_8220AC38` and `func_8220AC64`: own their two
  transition-control records as C objects at the original loader-cleared
  runtime addresses. Stock IDO emits their 248 retail bytes without three
  `COALESCE_AT_LUI` directives. Complete-module controls, host syntax and the
  full retail ROM gate pass; all function extents and legacy runtime addresses
  are preserved. See [the fragment 17 evidence](regions/fragments/17/fragment17_113A60.md).

- `func_8230009C` and `func_82300A78`: own the two- and three-halfword
  records they clear, keeping their original runtime addresses through NOLOAD
  placement. Stock IDO emits all 136 retail bytes without two coalescing
  directives. See [the fragment 19 evidence](regions/fragments/19/fragment19_121100.md).

- `func_82B062BC` and `func_82B07A5C`: own the initial state/flags/counter
  record and retain the counter's original address in its increment path.
  Stock IDO emits all 148 retail bytes without two coalescing directives.
  Both files pass normal/blank module controls, host syntax and a combined
  retail ROM gate with every function extent and legacy address preserved.
  See [the fragment 24 evidence](regions/fragments/24/fragment24_150C10.md).

- `func_82000098`: own the real trigger-state halfwords in C at their
  loader-cleared address. Stock IDO emits all 104 retail bytes directly,
  removing the whole-function hex replacement, eight relocation-target
  directives and one coalescing directive. Complete-module normal/blank
  controls, host syntax and a normal retail ROM gate pass; existing fade
  data, function extents and legacy addresses remain exact. See
  [the fragment 16 evidence](regions/fragments/16/fragment16_code.md).

- `func_8220BF68` and `func_8220D630`: own their three adjacent state
  halfwords. Signed stores and a normal two-iteration `for` loop remove two
  coalescing directives, a word rewrite and an instruction swap. All 264
  retail bytes match. See [the fragment 17 panel evidence](regions/fragments/17/fragment17_11B210.md).

- `func_82507B6C` and `func_82507BD0`: own their three-halfword state
  record and saved argument pair, retaining the original guarded reads and
  narrow call contract. All 124 retail bytes match without a whole-function
  hex replacement, nine relocation-target patches and two coalescing
  directives. Both files pass normal/blank controls, host syntax and the
  normal retail ROM gate with all function extents and legacy addresses
  preserved. See [the fragment 21 evidence](regions/fragments/21/fragment21_144790.md).

- `func_82507BFC`, `func_82507C48` and `func_82508620`: use actual
  owned state/flag records for their related accesses. Extending the existing
  header prefix by its flags and next halfword preserves its 16-byte BSS
  section; the cellular helper owns its six-byte prefix in another pinned
  section. Stock IDO emits all 216 retail bytes without three whole-function
  hex replacements or 29 relocation-target patches. Normal/blank controls,
  host syntax and the full retail ROM gate pass with all function extents and
  legacy addresses preserved. See [the restart evidence](regions/fragments/21/fragment21_144790.md)
  and [the cellular-state evidence](regions/fragments/21/fragment21_147D10.md).

- `func_8F600020`: own the complete runtime block cleared by the
  initializer and fragment loader, including its image view. Preparing real
  field pointers before clearing that block and copying the source value
  before clearing the adjacent halfword lets stock IDO emit all 124 retail
  bytes directly. This removes the hex replacement and 14 relocation-target
  patches. Module controls, host syntax and the normal full-ROM gate pass;
  a linker assertion enforces the original RAM footprint. See
  [the fragment 74 evidence](regions/fragments/74/fragment74_code.md).

- `func_84136D84`: own the four snapshot destination pointers as a
  zero-initialized C array at their original loaded addresses. An ordinary
  four-iteration `do` loop emits the six retail instructions, including store
  order and the return delay slot, without coalescing. Normal/blank module
  controls, host syntax, private ROM links and the normal native full-ROM gate
  pass; all function extents, legacy globals and previous C objects remain
  exact. See [the snapshot-pointer evidence](regions/fragments/79/fragment79_3A4030.md).

- `func_8821B3E0`: own the four-byte collected-value array and use one
  loop for the two marker bytes, followed by another for the four cleared
  values. The shared loop index replaces the artificial reset and repeated
  base expression. Stock IDO emits all 88 retail bytes without coalescing.
  Module controls, host syntax, both private ROM links and the normal native
  full-ROM gate pass with all function extents and legacy addresses preserved.
  See [the fragment 31 state evidence](regions/fragments/31/fragment31_189760.md).

- `func_86408F84`: compose the primitive/environment packed-color
  expressions using the SDK's byte-field macros and standard display-list
  commands. Their equivalent OR associations reproduce the retail operand
  order and subsequent register lifetimes, removing eight word rewrites and
  the old nested shifts. The complete module matches normally and with
  leading blanks; host syntax and the normal native full-ROM gate pass.
  No storage, linker, compiler or ABI change is needed. See
  [the palette-rendering evidence](regions/fragments/52/fragment52_2871C0.md).

- `func_8F401C30`: own the playback handle and model pointer cleared after
  releasing the preview pool. Preparing their real record lets stock IDO emit
  all 344 retail bytes directly. This removes the whole-function replacement,
  38 relocation-target patches and the switch-table word repair. Complete
  module controls, host syntax, both private ROM links and the normal native
  ROM gate pass with all function extents and legacy addresses preserved.
  See [the playback-state evidence](regions/fragments/72/fragment72_code.md).

- `func_82B055A0`: extend the existing runtime prefix through its three
  copied halfwords and four enable flags. An ordinary post-increment `do`
  loop initializes each flag once and reproduces the retail store order.
  All 108 bytes now match without a hex replacement, nine relocation patches
  or coalescing. Module controls, host syntax, private ROM links and the
  normal native full-ROM gate pass. See
  [the parameter-initializer evidence](regions/fragments/24/fragment24_150C10.md).

- `func_82B07960`: use the owned state and counter for the confirmation
  guard and terminal stores. This removes the old alias-based read and lets
  stock IDO emit all 252 retail bytes, replacing a hex substitution and 24
  relocation patches. The combined parameter/confirmation module and full
  retail ROM pass. Both functions leave fragment 24 free of the requested
  rewrite/coalescing directives. See
  [the confirmation evidence](regions/fragments/24/fragment24_150C10.md).

- `func_86600E00`: own the four existing model records and refresh their
  scale fields in an ordinary four-player `for` loop. Stock IDO emits all
  236 retail bytes, removing a hex replacement, 36 relocation patches,
  coalescing and the artificial one-iteration block. The loaded words in this
  range are relocation metadata consumed before the loader clears runtime
  storage. Module controls, host syntax, private links and the normal native
  full-ROM gate pass. See
  [the model-scale evidence](regions/fragments/54/fragment54_code.md).

- `func_83302D8C`: own the producer-proven 48-byte dialog context and use
  the formatter's actual 100-byte text buffer. Stock IDO emits all 784 retail
  bytes, including the original 152-byte frame, without coalescing, unused
  stack padding or false text-helper prototypes. Native module controls,
  host syntax, private links and the final normal full-ROM gate pass. See
  [the dialog-renderer evidence](regions/fragments/57/fragment57_code.md).

- `func_82E00868`: own the two six-word bounds records and the two extra
  dimensions at their existing loader-cleared addresses. Stock IDO emits all
  1,524 retail bytes with ordinary byte-pair expressions, removing a hex
  replacement and 53 relocation patches. Native module controls, sizeof
  assertions, host syntax, private ROM links and the final normal full-ROM
  gate pass. See
  [the event-bounds evidence](regions/fragments/66/fragment66_code.md).

- `func_82E01A00`: represent the width/height pair as a real bounds subobject
  and use its typed pointer, alongside the existing view-state prefix and
  its two dimensions. All 744 retail bytes now compile directly; the earlier
  1,524-byte callback remains exact. This removes the last 33 directives from
  fragment 66. Native module/sizeof/host controls, complete private ROM links
  and the normal native full-ROM gate pass. See
  [the alternate-bounds evidence](regions/fragments/66/fragment66_code.md).

- `func_82501490`: use one real return result and a bitset pointer consumed
  by the eight-bit scan. Stock IDO hoists the mask load while retaining the
  required pointer/value lifetimes, matching all 328 retail bytes. This
  removes a hex replacement, four relocation patches and dummy `result | 0`
  expressions. Whole-module normal/+20 controls, host syntax and the final
  native full-ROM gate pass without layout changes. See
  [the button-predicate evidence](regions/fragments/21/fragment21_13FFA0.md).

- `func_82702220`: use the verified menu/row types and a natural three-option
  `for` loop. Stock IDO emits all 324 retail bytes directly, removing seven
  word patches and the unused frame-padding array. The matching prototype
  and readable locals preserve all callers and the complete module.
  Normal/+20 controls, host syntax and the final native full-ROM gate pass,
  with no layout changes. See
  [the completion-routine evidence](regions/fragments/22/fragment22_14B090.md).

- `func_8230099C`: initialize its four transition rows with an indexed loop,
  owning the preceding fallback color and state halfwords as an eight-byte
  header and the actual row columns as a 34-byte record. Stock IDO emits all
  220 retail bytes directly, removing the whole-function hex replacement and
  46 relocation-target patches. The existing color callbacks consume the
  owned color, and the source reads use their real 36-byte entry layout.
  Normal/blank controls, host syntax and the normal native full-ROM gate pass
  with all function extents and legacy addresses preserved. See
  [the transition initializer evidence](regions/fragments/19/fragment19_121100.md).

- `func_86401DBC`: keep the first random draw inside the probability
  expression, multiply the existing width with a compound assignment, and
  pass the actual float field from both callers. Stock IDO emits all 420
  retail bytes without 30 word rewrites or the bit-reinterpretation call
  macro. Complete-module normal/blank controls, host syntax and the normal
  native retail ROM gate pass with all function/object symbols preserved.
  See [the emission evidence](regions/fragments/52/fragment52_27E4E0.md).

- `func_87F02104`: save and restore the four controllers' real `flags`
  fields with ordinary loops, using the existing controller header and a
  signed input-result temporary before narrowing to button bits. Stock IDO
  emits all 492 retail bytes after linking without the whole-function hex
  replacement or 13 relocation-target directives. Normal/blank controls,
  host syntax and the native full-ROM comparison pass. Function/storage
  extents and legacy addresses are unchanged; the unused `D_800CE088` alias
  retains its address with ELF type `NOTYPE` instead of `OBJECT`. See
  [the controller-loop evidence](regions/fragments/64/fragment64_324A10.md).

- `func_88203A18`: search the entries array by index rather than maintaining
  an explicit cursor local. Stock IDO generates the cursor induction itself,
  keeping capacity in V0 and the cursor in A2, and emits all 64 retail bytes
  without six word rewrites. Complete-module normal/blank controls, host
  syntax and the native full-ROM gate pass with function/object extents and
  legacy addresses preserved. See
  [the storage-search evidence](regions/fragments/31/fragment31_1768F0.md).

- `func_8F100B54`: traverse the existing six-byte menu records by index,
  read their typed timer field and dispatch using a typed record difference.
  Compiler-generated cursor induction preserves the two real base address
  loads; an end-first comparison matches the retail branch order. All 272
  bytes match without the duplicated two hex replacements and 20 relocation
  patches. Complete-module controls, host syntax and the native full-ROM
  gate pass with function/object extents and legacy addresses preserved.
  See [the menu traversal evidence](regions/fragments/69/fragment69_code.md).

- `func_81606800`: own its four-byte panel color-mode cache as a
  function-local static, and compare the cache before the incoming mode.
  Stock IDO emits all 192 retail bytes without the word rewrite. The existing
  fixed-address NOLOAD mechanism places the cache at `0x8160BE5C`; its
  original loaded zero initializer stays in the data image. Native module
  controls, independent linked comparison, host syntax and the full-ROM gate
  pass. Function/storage extents, legacy addresses and fragment boundaries
  are preserved; the legacy cache label becomes `NOTYPE` while the new C
  static owns the same word. See
  [the panel-cache evidence](regions/fragments/11/fragment11_D9DE0.md).

- `func_8AF00504`: keep the loader's actual work values in a local record,
  including its byte-sized tag key, and own the adjacent tag/flag pair as a
  function-local static. Stock IDO emits all 284 retail bytes without the hex
  replacement or its 18 relocation patches, and the dead stack local is gone.
  The existing fixed-address NOLOAD mechanism places the eight-byte state at
  `0x8AF2BF18`, inside the fragment loader's cleared range. Original relocation
  metadata remains in the load image. Native module controls, independent
  linked comparison, host syntax and the full-ROM gate pass. Existing storage
  extents, legacy addresses and fragment boundaries are preserved. See
  [the loader evidence](regions/fragments/44/fragment44_1EE290.md).

This leaves 331 directive occurrences and 23 affected functions. Coverage files and
compiler/tooling sources are unchanged.


## Function inventory

Pending means the directive is still present; the unpatched diagnostic is
an actual comparison attempt, not a completed replacement. Counts in this
table are baseline function directives, excluding the separate section word.

| Function | Source | Directives | State |
| --- | --- | ---: | --- |
| `func_800289B0` | [src/229E0.c](../src/229E0.c) | 18 | Pending |
| `func_80039808` | [src/340C0.c](../src/340C0.c) | 1 | Pending |
| `func_80071DD8` | [src/728D0.c](../src/728D0.c) | 5 | Pending |
| `func_81606800` | [src/fragments/11/fragment11_D9DE0.c](../src/fragments/11/fragment11_D9DE0.c) | 1 | Replaced with C |
| `func_83F001A8` | [src/fragments/15/fragment15_code.c](../src/fragments/15/fragment15_code.c) | 1 | Replaced with C |
| `func_82000098` | [src/fragments/16/fragment16_code.c](../src/fragments/16/fragment16_code.c) | 10 | Replaced with C |
| `func_82000100` | [src/fragments/16/fragment16_code.c](../src/fragments/16/fragment16_code.c) | 23 | Pending |
| `func_82001A78` | [src/fragments/16/fragment16_code.c](../src/fragments/16/fragment16_code.c) | 2 | Replaced with C |
| `func_82204744` | [src/fragments/17/fragment17_113A60.c](../src/fragments/17/fragment17_113A60.c) | 1 | Replaced with C |
| `func_82205B00` | [src/fragments/17/fragment17_113A60.c](../src/fragments/17/fragment17_113A60.c) | 3 | Pending |
| `func_822068E0` | [src/fragments/17/fragment17_113A60.c](../src/fragments/17/fragment17_113A60.c) | 17 | Pending |
| `func_8220AC38` | [src/fragments/17/fragment17_113A60.c](../src/fragments/17/fragment17_113A60.c) | 1 | Replaced with C |
| `func_8220AC64` | [src/fragments/17/fragment17_113A60.c](../src/fragments/17/fragment17_113A60.c) | 1 | Replaced with C |
| `func_8220BF68` | [src/fragments/17/fragment17_11B210.c](../src/fragments/17/fragment17_11B210.c) | 3 | Replaced with C |
| `func_8220D630` | [src/fragments/17/fragment17_11B210.c](../src/fragments/17/fragment17_11B210.c) | 1 | Replaced with C |
| `func_81700B8C` | [src/fragments/18/fragment18_code.c](../src/fragments/18/fragment18_code.c) | 3 | Replaced with C |
| `func_8230009C` | [src/fragments/19/fragment19_121100.c](../src/fragments/19/fragment19_121100.c) | 1 | Replaced with C |
| `func_8230099C` | [src/fragments/19/fragment19_121100.c](../src/fragments/19/fragment19_121100.c) | 47 | Replaced with C |
| `func_82300A78` | [src/fragments/19/fragment19_121100.c](../src/fragments/19/fragment19_121100.c) | 1 | Replaced with C |
| `func_82501490` | [src/fragments/21/fragment21_13FFA0.c](../src/fragments/21/fragment21_13FFA0.c) | 5 | Replaced with C |
| `func_82507B6C` | [src/fragments/21/fragment21_144790.c](../src/fragments/21/fragment21_144790.c) | 11 | Replaced with C |
| `func_82507BD0` | [src/fragments/21/fragment21_144790.c](../src/fragments/21/fragment21_144790.c) | 1 | Replaced with C |
| `func_82507BFC` | [src/fragments/21/fragment21_144790.c](../src/fragments/21/fragment21_144790.c) | 12 | Replaced with C |
| `func_82507C48` | [src/fragments/21/fragment21_144790.c](../src/fragments/21/fragment21_144790.c) | 12 | Replaced with C |
| `func_82508620` | [src/fragments/21/fragment21_147D10.c](../src/fragments/21/fragment21_147D10.c) | 8 | Replaced with C |
| `func_827000B8` | [src/fragments/22/fragment22_14A2E0.c](../src/fragments/22/fragment22_14A2E0.c) | 1 | Pending |
| `func_82702220` | [src/fragments/22/fragment22_14B090.c](../src/fragments/22/fragment22_14B090.c) | 7 | Replaced with C |
| `func_82B055A0` | [src/fragments/24/fragment24_150C10.c](../src/fragments/24/fragment24_150C10.c) | 11 | Replaced with C |
| `func_82B062BC` | [src/fragments/24/fragment24_150C10.c](../src/fragments/24/fragment24_150C10.c) | 1 | Replaced with C |
| `func_82B07960` | [src/fragments/24/fragment24_150C10.c](../src/fragments/24/fragment24_150C10.c) | 25 | Replaced with C |
| `func_82B07A5C` | [src/fragments/24/fragment24_150C10.c](../src/fragments/24/fragment24_150C10.c) | 1 | Replaced with C |
| `func_88203A18` | [src/fragments/31/fragment31_1768F0.c](../src/fragments/31/fragment31_1768F0.c) | 6 | Replaced with C |
| `func_8821B3E0` | [src/fragments/31/fragment31_189760.c](../src/fragments/31/fragment31_189760.c) | 1 | Replaced with C |
| `func_88223418` | [src/fragments/31/fragment31_1965A0.c](../src/fragments/31/fragment31_1965A0.c) | 2 | Pending |
| `func_8830765C` | [src/fragments/32/fragment32_1B8010.c](../src/fragments/32/fragment32_1B8010.c) | 2 | Pending |
| `func_88507370` | [src/fragments/34/fragment34_1C3FA0.c](../src/fragments/34/fragment34_1C3FA0.c) | 31 | Pending |
| `func_8AC06D8C` | [src/fragments/43/fragment43_1E5A10.c](../src/fragments/43/fragment43_1E5A10.c) | 1 | Replaced with C |
| `func_8AF00504` | [src/fragments/44/fragment44_1EE290.c](../src/fragments/44/fragment44_1EE290.c) | 19 | Replaced with C |
| `func_8AB07C34` | [src/fragments/45/fragment45_22AB80.c](../src/fragments/45/fragment45_22AB80.c) | 36 | Pending |
| `func_8AB07E6C` | [src/fragments/45/fragment45_22AB80.c](../src/fragments/45/fragment45_22AB80.c) | 31 | Pending |
| `func_8AB0A720` | [src/fragments/45/fragment45_22AB80.c](../src/fragments/45/fragment45_22AB80.c) | 3 | Pending |
| `func_8AE02398` | [src/fragments/46/fragment46_code.c](../src/fragments/46/fragment46_code.c) | 20 | Pending |
| `func_8AE02470` | [src/fragments/46/fragment46_code.c](../src/fragments/46/fragment46_code.c) | 22 | Pending |
| `func_87C03B10` | [src/fragments/48/fragment48_2597B0.c](../src/fragments/48/fragment48_2597B0.c) | 7 | Replaced with C |
| `func_864001E0` | [src/fragments/52/fragment52_27E4E0.c](../src/fragments/52/fragment52_27E4E0.c) | 1 | Pending |
| `func_86401DBC` | [src/fragments/52/fragment52_27E4E0.c](../src/fragments/52/fragment52_27E4E0.c) | 30 | Replaced with C |
| `func_86408F84` | [src/fragments/52/fragment52_2871C0.c](../src/fragments/52/fragment52_2871C0.c) | 8 | Replaced with C |
| `func_86600E00` | [src/fragments/54/fragment54_code.c](../src/fragments/54/fragment54_code.c) | 38 | Replaced with C |
| `func_83302D8C` | [src/fragments/57/fragment57_code.c](../src/fragments/57/fragment57_code.c) | 1 | Replaced with C |
| `func_83402B10` | [src/fragments/58/fragment58_code.c](../src/fragments/58/fragment58_code.c) | 6 | Pending |
| `func_87E04114` | [src/fragments/63/fragment63_306150.c](../src/fragments/63/fragment63_306150.c) | 13 | Pending |
| `func_87E07A2C` | [src/fragments/63/fragment63_308D70.c](../src/fragments/63/fragment63_308D70.c) | 2 | Pending |
| `func_87E07DD0` | [src/fragments/63/fragment63_30B540.c](../src/fragments/63/fragment63_30B540.c) | 2 | Replaced with C |
| `func_87F02104` | [src/fragments/64/fragment64_324A10.c](../src/fragments/64/fragment64_324A10.c) | 14 | Replaced with C |
| `func_87F025B8` | [src/fragments/64/fragment64_324FB0.c](../src/fragments/64/fragment64_324FB0.c) | 4 | Replaced with C |
| `func_87F06240` | [src/fragments/64/fragment64_328E40.c](../src/fragments/64/fragment64_328E40.c) | 1 | Pending |
| `func_82E00868` | [src/fragments/66/fragment66_code.c](../src/fragments/66/fragment66_code.c) | 54 | Replaced with C |
| `func_82E01A00` | [src/fragments/66/fragment66_code.c](../src/fragments/66/fragment66_code.c) | 33 | Replaced with C |
| `func_82901AE0` | [src/fragments/67/fragment67_33D6A0.c](../src/fragments/67/fragment67_33D6A0.c) | 17 | Pending |
| `func_829064D0` | [src/fragments/67/fragment67_342DB0.c](../src/fragments/67/fragment67_342DB0.c) | 15 | Pending |
| `func_8F100B54` | [src/fragments/69/fragment69_code.c](../src/fragments/69/fragment69_code.c) | 22 | Replaced with C |
| `func_8F401C30` | [src/fragments/72/fragment72_code.c](../src/fragments/72/fragment72_code.c) | 39 | Replaced with C |
| `func_8F600020` | [src/fragments/74/fragment74_code.c](../src/fragments/74/fragment74_code.c) | 15 | Replaced with C |
| `func_84136D84` | [src/fragments/79/fragment79_3A4030.c](../src/fragments/79/fragment79_3A4030.c) | 1 | Replaced with C |
| `func_84163380` | [src/fragments/79/fragment79_3D2C10.c](../src/fragments/79/fragment79_3D2C10.c) | 61 | Pending |
