.name "LOGIC"
.comment "logic"

ld %0, r2
and: and r1, r2, r3
zjmp %:or
or: or r1, r2, r3
zjmp %:xor
xor: xor r1, r2, r3
zjmp %:and
