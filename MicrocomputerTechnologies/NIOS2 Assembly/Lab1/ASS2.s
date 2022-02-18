.data

a_tri_l1: .hword 42
a_tri_l2: .hword 27
a_tri_area: .word 0

.global _start
.text

_start:
	movia r2, a_tri_l1
	ldh r3, (r2)
	movia r2, a_tri_l2
	ldh r4, (r2)	
	mul r5, r3, r4
	movi r2, 2
	div r6, r5, r2
	movia r2, a_tri_area
	stw r6, (r2)
	

endloop:
br endloop
.end