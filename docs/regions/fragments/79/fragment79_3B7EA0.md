# fragment79_3B7EA0

## 2026-10-28: func_841496C0 accepted; func_84148C74 requeue

- `func_841496C0`: damage modifiers on `Fragment79DamageContext`. Nothing
  happens when `unk_01` is 0xA5. Otherwise: ×1.5 when `type` matches either attacker
  type byte, `func_84124360(&damage, unk_06, type)`, halve for effect 0x97 with
  `unk_06 == 1`, then `func_800632CC` with the defender's two type bytes and
  `(defender[0x15] & 8) != 0`. This matched on the first draft.
- `func_84148C74` (requeue, 0.96): move chooser. Shape:

  ```c
  u8 move; u8 query[8];        /* this declaration order */
  move = func_84148BB4(side); if (move != 0xFF) return move;
  _bzero(query, 8); query[0] = side;
  if ((query[1] = func_84155D5C(side, func_84154B30(side)[1],
                                func_84154B30(1 - side)[1])) != 0) {
      func_841487A8(query); func_84148B40(query); return query[3];
  }
  if (func_84156618(side, func_84154B30(side)[1], 2)) func_84148AC8(query);
  else func_84148A4C(query);
  return query[3];
  ```

  Only the compiler temp holding the first `func_84154B30` result differs:
  retail puts it at `0x24`, ours at `0x20`. Any extra named local grows
  the frame to 0x40.
