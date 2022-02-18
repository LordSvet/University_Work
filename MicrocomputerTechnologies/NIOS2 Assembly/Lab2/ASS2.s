		.data
		.equ LED, 0x810

		.global _start
		.text
_start:		movi r4, 9
		call write_LED
		br endloop
		
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
