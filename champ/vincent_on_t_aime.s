
.name		"vincent_on_t_aime"
.comment	"I've jerk more beer than you drink"

sodomie:	live	%1
		fork	%:chiche
		zjmp	%:apwal

chiche:		sti	r1, %:cp, %2
		ldi	%:cp, %3, r4
		sti	r4, %:sodomie, %-4
		ldi	%:cp, %-1, r4
		sti	r4, %:sodomie, %-8
		ldi	%:cp, %-5, r4
		sti	r4, %:sodomie, %-12
		ldi	%:cp, %-9, r4
		sti	r4, %:sodomie, %-16
		ldi	%:cp, %-13, r4
		sti	r4, %:sodomie, %-20
		ldi	%:cp, %-17, r4
		sti	r4, %:sodomie, %-24
		ldi	%:cp, %-21, r4
		sti	r4, %:sodomie, %-28
		ldi	%:cp, %-25, r4
		sti	r4, %:sodomie, %-32
		ldi	%:cp, %-29, r4
		sti	r4, %:sodomie, %-36
		ldi	%:cp, %-33, r4
		sti	r4, %:sodomie, %-40
		ldi	%:cp, %-37, r4
		sti	r4, %:sodomie, %-44
		ldi	%:cp, %-41, r4
		sti	r4, %:shooter, %-48
		zjmp	%:my_live
		fork	%:sodomie

cp:		ld	%1, r1

apwal:		sti	r1, %:shooter, %1
		live	%1
		ld	%420, r8
		ld	%1, r5
		ld	%0, r11
		fork	%:sodomie

shooter:	live	%1
		sti	r8, %-420, r2
		sti	r8, %-420, r3
		zjmp	%:sodomie

my_live:	st	r1, %424242
		live	%424242
