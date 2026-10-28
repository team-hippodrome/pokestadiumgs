# fragment25_15BBC0

## 2026-10-28 — `func_821020B0`: requeue (three-item distance sort)

Compute `dist[i] = func_82102CE4(ref, func_82101B80(items[i]))` for three
items, then bubble-sort `items`/`dist` with three passes of
`j = 2..1: if (dist[j] + D_82103DB0 < dist[j - 1]) swap`. Retail keeps
`&dist[i]` and `items` pointers in saved registers, loads the tolerance
once, and walks the inner loop by pointer (`&dist[2]` down to `dist`, with
a byte offset 8 -> 0 into `items`). Index loops give 0.44. A pointer
rewrite gets unrolled by copt (127 instructions). The 240-second permuter
started from 7820.
