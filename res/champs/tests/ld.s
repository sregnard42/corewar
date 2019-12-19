.name "LD"
.comment "ld"

begin: ld 32, r2 #loads value positioned at PC - 5 % IDX_MOD into R2
st r2, 33
#ld 5, r3 #loads value positioned at PC + 5 % IDX_MOD into R3
#ld %-7, r4 #loads value -7 into R4
#ld %7, r5 #loads value 7 into R5
#ld 0, r6 #loads value at PC + 0 (= opcode = 2) into R6
#zjmp %0 #nothing happens
carry: ld %0, r7 #loads value 0 into R7, change carry to 1
zjmp %:begin #infinite loop
