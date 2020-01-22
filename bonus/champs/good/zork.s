#Ahah
.name "zork"
.comment "I'M ALIIIIVE"

l2:
l1:
	sti r1, %:live, %1
	and r1, %0, r1

live:
coucou: live %1
		zjmp %:live
