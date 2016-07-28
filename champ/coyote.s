.name "pre final"
.comment "jusqu'au bout"

l1:
	sti r1,%:live,%1
	zjmp %:live
	live %1
	zjmp %:l4
	zjmp %:l1
	live %1
	zjmp %:l2

live:
	live %1
	fork %19
	zjmp %:l2
	live %1
	zjmp %:live
	fork %21

l2:
	live %1
	zjmp %:live
	live %1
	fork %-111
	live %1
	fork %1
	zjmp %:l2
	fork %19
	
l4:
	live %1
	fork %-30
	zjmp %-1
	zjmp %:l2
	fork %25
	live %1
	zjmp %:l3
	
l3:
	live %1
	fork %7
	zjmp %:live
	live %1
	zjmp %:l3
	live %1
	fork %-11