.name "Staying' Alive"
.comment "And we're stayin' alive, stayin' alive"

sti r1, %:live, %1

live:   live %1
        ld %0, r2
        zjmp %:live
        