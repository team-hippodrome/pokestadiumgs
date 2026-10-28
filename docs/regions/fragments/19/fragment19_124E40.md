# fragment19_124E40

## func_82303D84 (accepted 2026-10-28)

Triangular 0..255 ramp over `arg0 % 45`: up over 0..4, flat 255 over 5..9, down
over 10..39, then 0. It must be a single-exit `if`/`else if` chain assigning
`result`. Early `return`s swap `v0`/`v1`. The parameter is `u32` (`divu`, no
`andi`); the caller's `u16` extern was retyped.
