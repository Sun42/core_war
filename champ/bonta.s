.name    "bonta"
.comment "fumoffu !!!"
.extend
	st r1,:essai+1
	st r1,:essai2+1
	st r1,:forka+1
	st r1,:forka+9
	fork %:essai2
	fork %:forka
label:
	xor r8,r8,r8
	zjmp %:essai

l:
        st      r1, :l1+1
        ld      %4, r3
l1:     live    %1
        ld      %:l1 - :l2, r2
l3:     ldi     %:l2, r2, r4
        sti     r4, %:l2 - 200, r2
        add     r2, r3, r2
live:   zjmp    %:l1 - 250
        xor     r4, r4, r4
        zjmp    %:l3
essai:
	live %1
	xor r8,r8,r8
	zjmp %:essai

essai2:
	live %1
	xor r8,r8,r8
	zjmp %:essai2

forka:
	live %1
	fork %:l
	xor r8,r8,r8
	zjmp %:forka

l2: