# fragment18_code

## 2026-10-28 — `func_817000A4` matched

Fragment setup: clears `D_81700DA0`, stores the `func_8004C8C0(0x13F)` result there, and if it is nonzero calls `func_8004C8C0(0x11C)` and runs `fragment18_main` over the four 0x24-byte entries at `D_81700DB0`. It returns `D_81700DA0` (reloaded). It needs an index loop (`D_81700DB0 + i * 0x24`); the pointer-walk forms compare against a precomputed end in the wrong register.
