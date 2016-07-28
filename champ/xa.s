.name "XaaroS"
.comment "If I win, it's a mistake."

l2:
	sti r1,%:live,%1
	and r1,%0,r1
	st r4,34
	st r4, r1
	ld 35,r4
	add r2,r3,r4
	st r4,24
	st r4,r7
	add r5,r6,r1
	st r1,3
	st r1,r7
	ldi 3,%4,r1
	zjmp %23
	live %1
	fork %18
	ldi 3,%4,r1
	zjmp %:live
	
live: 
	live %1
	sti r1,%:live,%1
	and r1,%0,r1
	st r4,34
	st r4, r1
	ldi 3,%4,r1
	add r2,r3,r4
	zjmp %23
	ldi 1,%45,r1
	live %1
	fork %34
	ld 30,r6
	st r1,16
	st r2,r5
	add r5,r6,r1
	st r6,54
	st r4,r6
	st r8,21
	and r2,%1,r3
	zjmp %:l2

