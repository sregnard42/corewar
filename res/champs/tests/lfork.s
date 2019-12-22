.name "LFORK"
.comment "lfork"

sti r1, %:live, %1
live:   live %1
lfork %2400
lfork %-2400
