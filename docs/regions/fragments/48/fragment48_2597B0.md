# Region notes — src/fragments/48/fragment48_2597B0.c

## 2026-11-03 — genuine perspective quotient match

`func_87C03B10` now matches all 80 retail bytes through stock IDO 7.1,
removing six `REWRITE_FUNCTION_WORD` directives and one
`SWAP_FUNCTION_WORDS`. The denominator's dot product remains an f32
expression, then widens into an f64 local. The numerator is an f32 product;
the f64 denominator promotes it for the division, and the f32 return narrows
the quotient. Writing the point's x component first in the product yields
the original multiplication operands. This agrees with the double denominator
already used by the neighboring projection helpers.

Named numerator/denominator variants first restored the instruction order but
left three register differences. A calibrated, one-worker, 60-second statement/
expression mutation search found the direct numerator expression. Its unused
numerator declaration and empty statements were removed before the actual
whole-file comparison. The installed C contains neither; the signature,
point/matrix accesses, expression grouping and arithmetic precision are
preserved. Compiler options and helper contracts were not changed.

Fresh unchanged/candidate normal/+20-leading-blank controls preserve all
allocated module bytes/layout, defined extents and semantic relocations. The
final installed source passed two more module controls, the normal host syntax
check, and `make -j1 COMPARE=1 RUN_CC_CHECK=1` under the native build. The
retail ROM MD5 is `1561c75d11cedf356a8ddb1a4a5f9d5d`. Coverage was not updated.
