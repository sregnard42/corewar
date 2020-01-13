.name "Staying' Alive"
.comment "And we're stayin' alive, stayin' alive"

sti r1, %:live, %1
sti r1, %:main, %1

main:   live %1
        fork %:live
        ld %0, r2
        zjmp %:main

live:   live %1
        ld %0, r2
        zjmp %:live
