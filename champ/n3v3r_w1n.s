##
##
## N3v3r w1n
## Bha il a encore jamais rien fais de bien... :p
##
##

.name		"N3v3r W1n"
.comment	"|\| 3 \/ 3 |2  -  \/\/ ! |\|....."

start:		fork	%:zork
		fork	%:wall1
		fork	%:wall2
		fork	%:wall3
		fork	%:wall4
		fork	%:wall5
		fork	%:zork

wall1:		fork	%:zork
		st	r1, -313
		st	r2, -313
		st	r3, -312
		st	r4, -312
		st	r5, -311
		st	r6, -311
		st	r7, -313
		st	r8, -313
		st	r9, -313
		st	r10, -313
		st	r11, -315
		st	r12, -313
		st	r13, -316
		st	r14, -313
		st	r15, -313
		st	r16, -317
		st	r17, -313
		st	r18, -318
		st	r19, -313
		st	r20, -313
		st	r21, -313
		st	r22, -313
		st	r23, -313
		st	r24, -313
		fork	%:zork

wall5:		fork	%:zork
		st	r1, -513
		st	r2, -513
		st	r3, -512
		st	r4, -512
		st	r5, -511
		st	r6, -511
		st	r7, -513
		st	r8, -513
		st	r9, -513
		st	r10, -513
		st	r11, -515
		st	r12, -513
		st	r13, -516
		st	r14, -513
		st	r15, -513
		st	r16, -517
		st	r17, -513
		st	r18, -518
		st	r19, -513
		st	r20, -515
		st	r21, -513
		st	r22, -513
		st	r23, -510
		st	r24, -514
		fork	%:zork

wall4:		st	r1, -413
		st	r2, -413
		st	r3, -412
		st	r4, -412
		st	r5, -411
		st	r6, -411
		st	r7, -413
		st	r8, -413
		st	r9, -413
		st	r10, -413
		st	r11, -415
		st	r12, -413
		st	r13, -416
		st	r14, -413
		st	r15, -413
		st	r16, -417
		st	r17, -413
		st	r18, -418
		st	r19, -413
		st	r20, -415
		st	r21, -413
		st	r22, -413
		st	r23, -410
		st	r24, -414
		fork	%:zork

wall2:		st	r1, -213
		st	r2, -313
		st	r3, -212
		st	r4, -212
		st	r5, -211
		st	r6, -211
		st	r7, -213
		st	r8, -213
		st	r9, -213
		st	r10, -213
		st	r11, -215
		st	r12, -213
		st	r13, -216
		st	r14, -213
		st	r15, -213
		st	r16, -217
		st	r17, -213
		st	r18, -218
		st	r19, -213
		st	r20, -215
		st	r21, -213
		st	r22, -213
		st	r23, -210
		st	r24, -214
		fork	%:zork

wall3:		st	r1, -113
		st	r2, -113
		st	r3, -112
		st	r4, -112
		st	r5, -111
		st	r6, -111
		st	r7, -113
		st	r8, -113
		st	r9, -113
		st	r10, -113
		st	r11, -115
		st	r12, -113
		st	r13, -116
		st	r14, -113
		st	r15, -113
		st	r16, -117
		st	r17, -113
		st	r18, -118
		st	r19, -113
		st	r20, -115
		st	r21, -113
		st	r22, -113
		st	r23, -110
		st	r24, -114
		fork	%:zork

live:		live	%42
		live	%42
		live	%42

zork:		ld	%-42, r16
		zjmp	%:wall1
		live	%42
		ld	%-42, r16
		zjmp	%:wall2
		live	%42
		ld	%-42, r16
		zjmp	%:wall3
		ld	%-42, r16
		zjmp	%:wall4
		ld	%-42, r16
		zjmp	%:wall5
		fork	%:live
		fork	%:zork

write_zork_l:	sti	  r1, %:wall1, %1
		sti	  r1, %:zork, %6
		sti	  r1, %:wall2, %11
		sti	  r1, %:zork, %16
		sti	  r1, %:wall3, %21
		sti	  r1, %:zork, %26
		sti	  r1, %:wall4, %31
		fork		%:wall1
		ld		%-42, r16
		fork	  %:live
		sti	  r2, %:wall1, %1
		sti	  r2, %:zork, %6
		sti	  r2, %:wall2, %11
		sti	  r2, %:zork, %16
		sti	  r2, %:wall3, %21
		sti	  r2, %:zork, %26
		sti	  r2, %:wall4, %31
		fork		%:wall2
		ld		%-42, r16
		fork		%:live
		sti	  r1, %:wall1, %1
		sti	  r3, %:zork, %6
		sti	  r3, %:wall2, %11
		sti	  r3, %:zork, %16
		sti	  r3, %:wall3, %21
		sti	  r3, %:zork, %26
		sti	  r3, %:wall4, %31
		fork		%:wall3
		ld		%-42, r16
		sti	  r1, %:wall1, %1
		sti	  r4, %:zork, %6
		sti	  r4, %:wall2, %11
		sti	  r4, %:zork, %16
		sti	  r4, %:wall3, %21
		sti	  r4, %:zork, %26
		sti	  r4, %:wall4, %31
		fork		%:wall4
		fork		%:live
		sti	  r1, %:wall1, %1
		sti	  r4, %:zork, %6
		sti	  r4, %:wall2, %11
		sti	  r4, %:zork, %16
		sti	  r4, %:wall3, %21
		sti	  r4, %:zork, %26
		sti	  r4, %:wall4, %31
		fork		%:wall4
		ld		%-42, r16
		fork	  %:zork