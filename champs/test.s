.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1
live:
	live %0
	ld %0, r2
	ld %:loop, r7
	zjmp %:live

