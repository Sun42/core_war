.name        "Floodeur"
.comment    "I'm Just A Floodeur"

start:	    ld    %42,r2
	    zjmp    %:floodeur

floodeur:    fork    %:liver
	     zjmp    %:start

liver:	    live    %42
	    sti    r1,%:floodeur,%21
	    and    r2,%0,r1
	    zjmp    %:liver
