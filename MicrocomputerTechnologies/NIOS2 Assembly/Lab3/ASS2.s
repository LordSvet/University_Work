		.data
		.global _start
		.text
		
_start:		movui r4, 67 #A
		call sendChar0
		call endloop
		
sendChar0:	movia r8, 0x864
		movia r9, 0x868
		andi r9, r9, 0b01000000
		srli r9, r9, 0x6
		movi r10, 0x1
		call loop
		ret
		
loop: 	bne r9, r10, loop
	stw r4, (r8)
	ret		
		
		
endloop:
br endloop
.end
