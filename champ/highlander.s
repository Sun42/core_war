.name "highlander"
.comment "il n'en restera qu'un"
.extend

	zjmp %:start
	zjmp %:fire
	fork %:fire
	zjmp %:combleur_de_douves					
	
l1:
 sti r1,%:live,%1
 zjmp %:live
 live %1
 fork %-11
 zjmp %:link3
 10ld %17, r2
 zjmp %:link4

live:
	 live %1
	 fork %-5
	 zjmp %:link3
	 live %1
	 fork %-5

link2:
	 live %1
	 zjmp %:live
	 fork %-111
	20 zjmp %:link5
	 fork %:back_defense
	 zjmp %:fire		

link4:
	 live %1
	 fork %-30
	 fork %21
	 zjmp %:link3
	 fork %-1
	 zjmp %:link2
	 zjmp %-42
	 30live %1

link3:
	 live %1
	 fork %19
	 zjmp %:live
	 zjmp %:link2
	 zjmp %:link2
	 fork %-11
	 live %1
	 zjmp %:back_defense	

link5:
	 live %1
	 40fork %1
	 live %1
	 zjmp %:link5
	 zjmp %:live
	 zjmp %:clearer	
	 fork %-2

back_defense:

	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	   50                     st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	                        st   r4, -400
	     60                   st   r4, -400
	                        st   r4, -400
				st   r4, -400
				 st   r4, -400
				 st   r4, -400
				 st   r4, -400
				 st   r4, -400
				 st   r4, -400
				 st   r4, -400
				 st   r4, -400
		70		 st   r4, -400
				 st   r4, -400
clearer:
	        sti     r1, %:live, %1
	        fork %:back_defense
	        ld      %1, r2
	        add     r1,r3,r4
	        live    %42

combleur_de_douves:	     zjmp %:return
	                     live %0
return:
	        80fork %22
	        zjmp %:start
	        fork %42
	
start:
	         zjmp %:live
			
		

fire:	   ld      %24,r9
	        add     r1,r9,r6
	        sub     r2,r3,r5
	        live    %1
	        ld      %50,r8
	        add     r4,r7,r10
	        90fork    %:live
	        fork    %:clearer
	        zjmp    %:fire2


fire2:
	        ld      %42,r2
	        ld      %0,r3
	        ld      %19,r4
	        ld      %29,r5
	        fork    %42
	        fork    %:live
	        zjmp    %:fire3
fire3:	  live    %1
	        sti     r10,%-80,r2
	  100      sti     r10,%-80,r3
	        sti     r10,%-80,r4
	        sti     r10,%-80,r10
	        add     r5,r6,r5
	        add     r3,r1,r3
	        add     r8,r8,r8
	        sub     r3,r5,r3
	        zjmp    %:fire2
	        ld      %0,r11
	        zjmp    %:fire3
	        zjmp    %:return
	        zjmp    %:back_defense	