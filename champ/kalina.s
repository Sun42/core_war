.name		"khalinail"
.comment	"on verra plus tard ..."
.extend
	
# strategie :	 preparer une batterie de forks et de quoi se proteger des torpilles

#point d'entree
#initialise les live
	xor	r2, r2, r2
start:
	zjmp	%:_start
	zjmp	%:_start
	zjmp	%:_start
	zjmp	%:_start
	zjmp	%:_start
	zjmp	%:_start
	zjmp	%:_start
	zjmp	%:_start
_start:	
	sti	r1, %:live, %1
	sti	r1, %:live_fork, %1
	sti	r1, %:loop, %1
	sti	r1, %:do, %1
	sti	r1, %:core, %1
	sti	r1, %:copy_loop, %1	
init:	
	sti	r1,%:replik,%1
	sti	r1,%:replik,%6
	sti	r1,%:replik,%11
	sti	r1,%:replik,%16
	sti	r1,%:replik,%21
	sti	r1,%:replik,%26
	sti	r1,%:replik,%31
	sti	r1,%:replik,%36
	sti	r1,%:replik,%41
	sti	r1,%:replik,%46
	sti	r1,%:replik,%51
	sti	r1,%:replik,%56
	sti	r1,%:replik,%61
	sti	r1,%:replik,%66
	sti	r1,%:replik,%71
	sti	r1,%:replik,%76
	sti	r1,%:replik,%81
	sti	r1,%:replik,%86
	sti	r1,%:replik,%91
	sti	r1,%:replik,%94
	sti	r1,%:replik,%97
	sti	r1,%:replik,%100
live:
	live	%42
#maintenant que c'est fait ...
	sti	%09, %:start, %0
	sti	%:eject, %:start, %1
	sti	%09, %:start, %3
	sti	%:eject, %:start, %4
	sti	%09, %:start, %6
	sti	%:eject, %:start, %7
	sti	%09, %:start, %9
	sti	%:eject, %:start, %10
	sti	%09, %:start, %12
	sti	%:eject, %:start, %13
	sti	%09, %:start, %15
	sti	%:eject, %:start, %16
	sti	%09, %:start, %18
	sti	%:eject, %:start, %19
	sti	%09, %:start, %21
	sti	%:eject, %:start, %22
#... le start devient un saut pas tres utile
scan:
	fork	%:core
	ld	%150994944, r4
do:
	live	%42
	sti	r4, %:start - 509, r5
	sti	r4, %:eject + 54, r5
	add	r5, %5, r5
	fork	%:do
	
#bon, combien de fois allons nous forker ?
core:
	live	%42
	ld	%42, r2
	ld	%1, r3
loop:
	live	%42
	sub	r2, r3, r2
	fork	%:forker
	xor	r4,r4,r4
	zjmp	%:loop
forker:
live_fork:
	live	%42
#ce serait bien de se repliquer aussi
replik_base:
test_flag:
	ld	%:flag + 1, r8
	sub	r1, r8, r8
	zjmp	%:replik
	ld	%:scan - :eject, r2
	ld	%4, r3
copy_loop:
	live	%42
	ldi	%:eject, r2, r4
	sti	r4, %:forker - 1800, r2
	sti	r4, %:eject + 180, r2
	add	r2, r3, r2
	zjmp	%:replik
	xor	r4, r4, r4
	zjmp	%:copy_loop
replik:
	live	%42
set_flag:
	sti	r1, %:flag, %1
flag:	live	%42
	fork	%:forker + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:forker + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:forker + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:forker + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:eject + 180
	live	%42
	fork	%:replik_base
	live	%42
	live	%42
	live	%42
	live	%42
	fork	%:eject
#Bye bye la torpille
eject:
