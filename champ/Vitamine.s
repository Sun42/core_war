.name		"Vitamine"
.comment	"Parsque c'est bon pour la sante"

	ld	%6, r7
	ld	%1, r8
	ld	%66, r13
	ld	%8, r13
	ld	%396, r13
	ld	%85, r13
	ld	%44, r13
	ld	%69, r13
	ld	%18, r13
	ld	%48, r13
	add     r8, r12, r8
start:	ld	%0, r3
	zjmp	%:goto_1
	ld	%48, r13
	ld	%48, r13

get_n01:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n02:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n03:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n04:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n05:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n06:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n07:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n08:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n09:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n10:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n11:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n12:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n13:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n14:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n15:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n16:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n17:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n18:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n19:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n20:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n21:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n22:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n23:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n24:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n25:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n26:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n27:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n28:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n29:sti	r1, r3, r4
	live	%42
	zjmp	%-410

get_n30:sti	r1, r3, r4
live_0:	live	%42
	zjmp	%-410

get_n31:sti	r1, r3, r4
	live	%42
	zjmp	%:start

get_n32:sti	r1, r3, r4
	live	%42
	zjmp	%-410

goto_1:	ld	%-400, r3
	st	r1, 365
	st	r1, 296
	fork	%:end
	fork	%:proc_1
	ldi	r5, %343, r1
	ld	%0, r4
	ld	%0, r5
	zjmp	%:live_1

prepa_1:zjmp	%:get_n01
prepa_2:zjmp	%:get_n02
prepa_3:zjmp	%:get_n03
prepa_4:zjmp	%:get_n04
prepa_5:zjmp	%:get_n05
prepa_6:zjmp	%:get_n06
prepa_7:zjmp	%:get_n07
prepa_8:zjmp	%:get_n08
prepa_9:zjmp	%:get_n09
prepa_a:zjmp	%:get_n10
prepa_b:zjmp	%:get_n11
prepa_c:zjmp	%:get_n12
prepa_d:zjmp	%:get_n13
prepa_e:zjmp	%:get_n14
prepa_f:zjmp	%:get_n15
prepa_0:zjmp	%:get_n16

live_3:	live	%42
	fork	%:prepa_1
	zjmp	%:get_n17

live_4:	live	%42
	fork	%:prepa_2
	zjmp	%:get_n18

live_5:	live	%42
	fork	%:prepa_3
	zjmp	%:get_n19

live_6:	live	%42
	fork	%:prepa_4
	zjmp	%:get_n20

live_7:	live	%42
	fork	%:prepa_5
	zjmp	%:get_n21

live_8:	live	%42
	fork	%:prepa_6
	zjmp	%:get_n22

live_9:	live	%42
	fork	%:prepa_7
	zjmp	%:get_n23

live_10:live	%42
	fork	%:prepa_8
	zjmp	%:get_n24

fight_1:fork	%:live_3
	live	%42
	fork	%:prepa_9
	zjmp	%:get_n25

fight_2:fork	%:live_4
	live	%42
	fork	%:prepa_a
	zjmp	%:get_n26

fight_3:fork	%:live_5
	live	%42
	fork	%:prepa_b
	zjmp	%:get_n27

fight_4:fork	%:live_6
	live	%42
	fork	%:prepa_c
	zjmp	%:get_n28

virus_1:live	%42
	fork	%:fight_1
	fork	%:live_7
	live	%42
	fork	%:prepa_d
	zjmp	%:get_n29

virus_2:live	%42
	fork	%:fight_2
	fork	%:live_8
	live	%42
	fork	%:prepa_e
	zjmp	%:get_n30

virus_3:fork	%:virus_1
	live	%42
	fork	%:fight_3
	fork	%:live_9
	live	%42
	fork	%:prepa_f
	zjmp	%:get_n31

live_1:	live	%42
	sub	r7, r8, r7
	zjmp	%:live_2

	fork	%:live_1
	ld	%0, r2
	zjmp	%:live_1

live_2:	live	%42
	fork	%:virus_3
	fork	%:virus_2
	live	%42
	fork	%:fight_4
	fork	%:live_10
	live	%42
	fork	%:prepa_0
	zjmp	%:get_n32

	sti	r1, r3, r4
	live	%42
	zjmp	%:live_0

	sti	r1, r3, r4
proc_0:	ldi	r5, %-6, r1
	ld	%12, r4
	ld	%0, r5
	zjmp	%:live_1

proc_1:	ldi	r5, %-33, r1
	ld	%8, r4
	ld	%0, r5
	zjmp	%:live_1

end:	fork	%:proc_0
	ldi	r5, %-63, r1
	ld	%4, r4
	ld	%0, r5
	zjmp	%:live_1
	ld	%4, r12
	ld	%12, r13
	ld	%421, r14
	live	%42