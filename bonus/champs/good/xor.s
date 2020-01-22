.name "XOR"
.comment "xor"

ld %1, r2
ld %3, r3
xor r2, r3, r4
xor %1, %3, r4
xor -5, 12, r4

