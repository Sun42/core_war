##
##  Fougiou
##
## Made by julien lacroix
## Login   <lacroi_j@epita.fr>
##

.name "Fougiou"
.comment "Comment il se la pete"
.extend

main:
	fork	%:live
	st      r1, :live+1
	st	r2, :live+1
	st	r3, :live+10
	st	r1, :live+20
	st	r1, :live+30
	st	r1, :live+40
	st	r1, :live+100
	st	r1, :live+110
	st	r1, :live+120
	st	r1, :live+200
	ld	%0, r2

live:	live	%:live
	fork	%:live
	zjmp	%:main
