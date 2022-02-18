		.data
		.equ BUTTONS, 0x840

		.global _start
		.text
_start:		
loop:		call read_KEY0
		call read_KEY3
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
FINISH:	
	
endloop:
br endloop
.end
