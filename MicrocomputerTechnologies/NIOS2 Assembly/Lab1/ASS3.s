.data

sum: .word 0
num1: .word 5

.global _start
.text

_start:
	movi r8, 0    #i
	movia r2, sum
	ldw r3, (r2)
	movia r2, num1
	ldw r4, (r2)
	movi r5, 100
	movi r7, 1
	
	bge r4 , r5, ELSE
LOOP:	add r3, r3, r8
	add r8, r8, r7
	add r8, r8, r7
	bge r8, r4, FINISH
	br LOOP
	
ELSE:	sub r3, r3, r7
	
FINISH:	
	
endloop:
br endloop
.end
