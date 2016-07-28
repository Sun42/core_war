.name "Fulbert"
.comment "Laymain's champ..."
.extend


main:	fork	%:act
	fork	%:run
init:	sti	r1, %:live, %1
live:	live	%0
	fork	%:end
	ld	%0, r4
	zjmp	%:init
carry:	ld	%0, r1
shield:	zjmp	%:shield
act:	st	r1, %:alive, %1
alive:	live	%0
	fork	%:back
	fork	%:esc
	ld	%0, r4
	zjmp	%:esc
back:	sti	r1, %:main, %-400
	sti	r1, %:main, %-390
	sti	r1, %:main, %-380
	sti	r1, %:main, %-370
	sti	r1, %:main, %-360
	sti	r1, %:main, %-350
	sti	r1, %:main, %-340
	sti	r1, %:main, %-330
	sti	r1, %:main, %-320
	sti	r1, %:main, %-310
	sti	r1, %:main, %-300
	sti	r1, %:main, %-290
	sti	r1, %:main, %-280
	sti	r1, %:main, %-270
	sti	r1, %:main, %-260
	sti	r1, %:main, %-250
	sti	r1, %:main, %-240
	sti	r1, %:main, %-230
	sti	r1, %:main, %-220
	sti	r1, %:main, %-210
	sti	r1, %:main, %-200
	sti	r1, %:main, %-190
	sti	r1, %:main, %-180
	sti	r1, %:main, %-170
	sti	r1, %:main, %-160
	sti	r1, %:main, %-150
	sti	r1, %:main, %-140
	sti	r1, %:main, %-130
	sti	r1, %:main, %-120
	sti	r1, %:main, %-110
	sti	r1, %:main, %-100
	sti	r1, %:main, %-90
	sti	r1, %:main, %-80
	ld	%0, r4
	zjmp	%:act
esc:	fork	%:run
	fork	%:init
	fork	%:end
	fork	%:init
	fork	%:end
	fork	%:init
	fork	%:end
	fork	%:init
	fork	%:end
	fork	%:init
	fork	%:end
	ld	%0, r4
	zjmp	%:esc
run:	sti	r1, %:rlive, %1
rlive:	live	%0
	fork	%:esc
	fork	%:back
	ld	%0, r4
	zjmp	%:run
end:	sti	r1, %:elive, %1
elive:	live	%0
	ld	%0, r4
	zjmp	%:end
end2:	sti	r1, %:elive2, %1
elive2:	live	%0
	fork	%:act
	ld	%0, r4
	zjmp	%:end2
