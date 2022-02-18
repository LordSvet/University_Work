.data

arrayA:	.word 1
	.word 2
	.word 3
	.word 4
	.word 5
	.word 6
	.word 7
	.word 8
arrayB:	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0
	.word 0

.global _start
.text

_start:

	movi r8, 0 #i
	movi r9, 42 #c
	movia r2, arrayA
	movia r3, arrayB
	#addi r2, r2, 4
	#ldw r3, (r2)
	movi r13, 8
	
	blt r8 , r13 , LOOP
LOOP:	ldw r4, (r3) #b
	ldw r5, (r2) #a
	add r4, r5, r9
	stw r4, (r3)
	addi r8, r8, 1
	addi r2, r2, 4
	addi r3, r2, 4
	bge r8, r13, FINISH
	br LOOP
	
FINISH:	

endloop:
br endloop
.end
