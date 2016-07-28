.name "marvin_is_back"
.comment "3S powered..."
.extend

	ld %484,r5		; sti atak // r9 useless/r5 sti ini /r6 delta
	ld %4,r6		; delta dec //r1 num/ r2-r8 ldi
	ld %-100,r11
	fork %:fork1		; st 2 ld 5 live 5 add 6 fork 600
	st r1,:fork2+1
fork1:	fork %:fork2
	ld %42,r4
	st r1,:fork5+1
	st r1,:fork8+1
	st r1,:fork11+1
fork2:	live %1
fork3:	fork %:fork4
	ld %0,r8
	st r1,:fork13+1
fork4:	fork %:fork5
	st r1,:master3+1
	add r5,r6,r5		; r5 -> r5 + 4
fork5:	live %1
fork6:	fork %:fork7
	st r1,:fork5+1
	add r5,r6,r5		; r5 -> r5 + 8
	st r1,:fork11+1
fork7:	fork %:fork8
	add r5,r6,r5		; r5 -> r5 + 12
	st r1,:fork2+1
fork8:	live %1
fork9:	fork %:fork10
	ld %0,r8
	st r1,:master3b+1
	st r1,:fork13b+1
fork10:	fork %:fork11
	add r5,r6,r5		; r5 -> r5 + 16
	st r1,:fork13+1
	st r1,:fork8+1
fork11:	live %1
fork12:	fork %:fork14
	ld %0,r8
	add r5,r6,r5		; r5 -> r5 + 20
fork14:	fork %:fork13b
	st r1,:fork5+1
fork13:	live %1
	ld %-455,r7		; decalalge sti 437
start1:	fork %:start2
	fork %:start3
	ld %0,r8
	ldi %:master0,r8,r2	; stock le master decalle de r8 dans r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
start3:	ld %8,r8
	ldi %:master0,r8,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
start4:	ld %12,r8
	ldi %:master0,r8,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
start2:	fork %:start4
	ld %4,r8
	ldi %:master0,r8,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
a1:	st r1,r2		; a1 equivalent premiere zone atak frontale
a2:	st r1,r2		; a2 equivalent deuxieme zone atak frontale
master0:sti r2,r7,r8
master3:live %1
	zjmp %-465
	lfork %0		; decalage jump (-5 6/16+ 10/16-) top:	442 // the return of marvin = -10 de ld sti
a3:	st r1,r2		; a3 equivalent 1ere zone atak arriere
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
a4:	st r1,r2		; a4 equivalent 2nde zone atak arriere
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
a1b:	st r1,r2		; a1b equivalent premiere zone atak frontale du second groupe de process
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
a2b:	st r1,r2		; a2b equivalent 2nde zone atak frontale du second groupe de process
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
	st r1,r2
master0b:sti r2,r7,r8
master3b:live %1
	zjmp %-465		; decalage jump (-5 6/16+ 10/16-) top:	442 // the return of marvin = -10 de ld sti
a3b:	st r1,r2		; a3b equivalent 1ere zone atak arriere du second groupe de process
a4b:	st r1,r2		; a4b equivalent 2nde zone atak arriere du second groupe de process
fork13b:live %1
	add r5,r6,r5		; r5 -> r5 + 24 (6 * 4)
start1b:fork %:start2b
	fork %:start3b
	ld %0,r8
	sub r9,r5,r7		; decalalge sti
	ld %0x0f0f0f0f,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
start3b:ld %28,r8
	sub r9,r5,r7		; decalalge sti
	ld %0x0f0f0f0f,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
start4b:ld %72,r8		; 28+28+16
	add r9,r5,r7		; decalalge sti
	ld %0x0f0f0f0f,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
start2b:fork %:start4b
	ld %101,r8		; 28+28+28+16+1 pour le balayage
	add r9,r5,r7		; decalalge sti
	ld %0x0f0f0f0f,r2
	and r4,r4,r4
	zjmp %:master0
	ld %0,r9
	zjmp %:master0b
