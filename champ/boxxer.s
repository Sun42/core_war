#
# boxer.s for corewar
#
# kikoulol team
#
# 
#
.name "BoxXxeR"
.comment "just a beta live"

clac:	sti	r1,%:live,%42
	sti	r1,%:prout,%1
	zjmp	%:live
	sti	r1,%:droite,%1
	zjmp	%:live
	sti	r1,%:gauche,%1
	zjmp	%42
	live	%1
	zjmp	%:tete
	add	r10,r12,r15
	zjmp	%:gauche
	live	%5
	ld	%1,r8
        and	r1,%0,r1
	add	r15,r1,r1
	zjmp    %:live
	ld	%2,r4
	zjmp	%:clac
		 

live:   live	%777
	# fork	%:clac
	
prout:  live	%1
	zjmp	%20
	add	r10,r12,r15
#	fork	%4
#       zjmp	%:live
	zjmp	%:droite
	
droite:	add	r10,r12,r15	
	zjmp	%:live
	fork	%10
	zjmp	%:live
	zjmp	%20
	ld	%0,r7
#	aff	r7
#	zjmp	%:tete
	zjmp	%:live
	fork	%:gauche
	zjmp	%:live

tete:	ld 	%666,r8
	zjmp	%:live
	live	%159
	zjmp	%:live
	add	r7,r9,r3
	zjmp	%:live
#	fork	%54	
	zjmp	%:live
	sti	r9,%123,%0
	sti	r6,%:droite,%69
	zjmp	%:live
	ld	%52,r3
#	aff	r3
	zjmp	%:live
	aff	r3
	zjmp	%:live

gauche: live	%0
	zjmp	%:live
	add	r7,r9,r3
        zjmp	%:prout
	zjmp	%:live
	fork	%69	
	zjmp	%:live
	sti	r6,%:tete,%21
#	sti	r9,%123,%0
	zjmp	%:live