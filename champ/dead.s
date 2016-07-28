.name "DeadEye champ"
.comment "Mort d'avance"
.extend

start:	sti r1,%:live,%1	#prepare sa premiere vie

live:
	live %42		#alive!
	fork %:shoot
	fork %:salive
	ld %4,r4
	zjmp %:alive

backshoot:
	sti r2,%:start,r6
	sti r1,9,%0		#on sait jamais les attaques de fourbes
	live %42		#evidemment...
	sub r6,r4,r6
	sti r3,%:start,r6
	fork %:salive
	sti r1,9,%0		#on sait jamais les attaques de fourbes
	live %42		#evidemment...
	fork %:stbackshoot
	ld %4,r4
	zjmp %:backshoot

stbackshoot:
	st r2,0
	st r3,0
	zjmp %:backshoot

shoot:
	ld %-4,r6
	ld %0,r5
	fork %:stbackshoot	#on se protege l'arriere train
	fork %:stpreshoot	#on se protege l'avant train xD
	add r1,%0,r1
	zjmp %:start

salive:
	sti r1,%:alive,%1	#prepare les live
	sti r1,%:alive,%6
	sti r1,%:alive,%11
	sti r1,%:alive,%16
	sti r1,%:alive,%21
	sti r1,%:alive,%26
	sti r1,%:alive,%31
	sti r1,%:alive,%36
	sti r1,%:alive,%41
	sti r1,%:alive,%46
	sti r1,%:alive,%51
	sti r1,%:alive,%56
	sti r1,%:alive,%61
	sti r1,%:alive,%66
	sti r1,%:alive,%71

alive:
	live %42		#live comme un porc
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	live %42
	ld %4,r4
	zjmp %:alive		#encore un tour

stpreshoot:
	st r2,0
	st r3,0

preshoot:
	sti r2,%:write,r5
	sti r1,9,%0		#on sait jamais les attaques de fourbes
	live %42		#evidemment...
	add r5,r4,r5
	sti r3,%:write,r5
	fork %:alive
	fork %:stpreshoot
	ld %4,r4
	zjmp %:preshoot

write:				#la ou on ecrit...
