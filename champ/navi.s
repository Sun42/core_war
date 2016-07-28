.name		"Navi"
.comment	"Close the world ! !txeN ehT nepO"

wired:	sti	r1,%:live,%1
        and	r1,%0,r1

live:   live	%1
	fork	%:layer
        zjmp	%:live

boom:	sti	r16,%:wired,%0
	add	r10,r12,r15
	fork	%:live
	fork	%:cold
	zjmp	%0

zlock:	ld 	%1234,r8
	live	%159
	sti	r6,%:layer,%21
	sti	r9,%123,%0
	ld	%0,r7

cold:	fork	%:boom
	live	%0
	add	r7,r9,r3
        zjmp	%:live

layer:	live	%422
	fork	%:boom
	fork	%:wired
	live	%512
	sub	r3,r5,r3
	zjmp	%:cold
	ld	%0,r11
	fork	%:live
	live	%64
	sti	r11,%1,%16
	sti	r7,%147,%753
	fork	%:zlock
	sti	r2,%:cold,%777
	sti	r6,%:live,%123
	sti	r14,%:live,%321
	sti	r5,%1024,%:wired
	ld	%0,r11
	zjmp	%:wired