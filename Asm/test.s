.name        "Floodeur"
.comment    "I'm Just A Floodeur"

start:
	ld    %42,r2
	ld    42,r2
	st r1,%42
	st r1,42
	add r1,r2,r3
	sub r1,r2,r3
	and r1,r1,r1
	and %42,r1,r1
	and 42,r1,r1
	and r1,r1,r1
	and %42,42,r1
	and 42,%42,r1
	and r1,r1,r1
	and %42,42,r1
	and 42,%42,r1

	    or %42,r1,r1
	    or 42,r1,r1
	    or r1,r1,r1
	    or %42,42,r1
	    or 42,%42,r1
	    or r1,r1,r1
	    or %42,42,r1
	    or 42,%42,r1

            xor %42,r1,r1
	    xor 42,r1,r1
	    xor r1,r1,r1
	    xor %42,42,r1
	    xor 42,%42,r1
            xor r1,r1,r1
	    xor %42,42,r1
	    xor 42,%42,r1

	zjmp %42

	ldi r1,%42 ,r1
	ldi %42,%42 ,r1
	ldi 42,%42 ,r1
        ldi r1,r2 ,r1
	ldi %42,r2 ,r1
	ldi 42,r1 ,r1

	sti r1,r2, %42
	sti r1,%42,%42
	sti r1,42,%42
	sti r1,r2,r1
	sti r1,%42,r2
	sti r1,42,r2

	fork %42

	lld %42,r2
	lld 42,r2

	lldi r1,%42 ,r1
	lldi %42,%42 ,r1
	lldi 42,%42 ,r1
	lldi r1,r2 ,r1
	lldi %42,r2 ,r1
	lldi 42,r1 ,r1

	lfork %42

	aff r3
	live    %42
