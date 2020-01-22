.name "AND"
.comment "and"

ld %1, r2
ld %3, r3
and r2, r3, r4
and %1, %3, r4
and -5, 12, r4

