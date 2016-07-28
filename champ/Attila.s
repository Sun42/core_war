.name "Roi des TekHuns"
.comment "Il n'y a pas que l'herbe qui ne repouse plus"


start:	xor r2, r2, r3
	fork %:init
	st r1, 66
	st r1, 48
	ld %0, r8
	ld %0, r9
	ld 28, r4
	ld 27, r5
	ld 26, r6
	ld 25, r7
	xor r2, r2, r3
	zjmp %:wall
fuck:	live %132
	xor r1, r1, r1
	zjmp %:fuck
wall:	live %42
	st r8, -78
	st r9, -79
	st r4, -80
	st r5, -81
	st r6, -82
	st r7, -83
	st r4, -84
	st r5, -85
	st r6, -86
	st r7, -87
	st r4, -88
	st r5, -89
	st r6, -90
	st r7, -91
	xor r2, r2, r3
	zjmp %:wall
init:	sti r1, %:cpy, %1
	sti r1, %:fork, %1
	sti r1, %:live, %1
	sti r1, %:live2, %1
	sti r1, %:live3, %1
	sti r1, %:live4, %1
	fork %8
	zjmp %3
	zjmp %3
live4:	live %0
	fork %8
live2:	live %0
	fork %:fight
live3:	live %0
fight:	st r1, 6
	live %1
	fork %:fork
live:	live %0
fork:	live %0
	fork %:fork1
fork0:	fork %:fork2
	ldi %:cpy, %0, r3  !!!!!!!!!
	ld %0, r4
	ld %5, r5
	xor r10, r10, r10
	zjmp +
%:cpy
fork1:	fork %:fork3
	ldi %:cpy, %4, r3
	ld %4, r4
	ld %5, r5
	xor r10, r10, r10
	zjmp %:cpy
fork2:	ldi %:cpy, %8, r3
	ld %8, r4
	ld %5, r5
	xor r10, r10, r10
	zjmp %:cpy
fork3:	xor r10, r10, r10
	zjmp %:fight
cpy:	live %777
	sti r3, r4, r5
torped: