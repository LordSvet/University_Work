		.data
		.equ BUTTONS, 0x840
		.equ LED, 0x810

		.global _start
		.text
_start:		
loop:		call read_KEY0
		movi r21, 1
		mov r18, r2
		bne r18, r21, SKIP
		addi r17, r17, 1
SKIP:		call read_KEY3
		mov r19, r3
		bne r19, r21, SKIP2
		movi r17, 0	
SKIP2:		mov r4, r17
		call write_LED
		br loop
		
read_KEY0:	movia r5, BUTTONS
		movi r11, 1
		ldw r12, (r5)
		AND r11, r12, r11
		mov r2, r11
		ret
read_KEY3:	movia r5, BUTTONS
		movi r11, 8
		movi r13, 8
		ldw r12, (r5)
		AND r11, r12, r11
		beq r11, r13, ONE
		bne r11, r13, TWO
ONE:		movi r11, 1
TWO:		mov r3, r11
		ret	
		
write_LED:	mov r10, r4
		movi r11, 15
		AND r12, r10, r11
		movia r9, LED
		stw r12, (r9)
		ret
		
		
FINISH:	
	
endloop:
br endloop
.end

