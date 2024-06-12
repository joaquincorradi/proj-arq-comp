.text
.global autof
autof:
	PUSH(R4,R5,R6,LR)
	MOV R4, #15
	LDR R5, =array

loop:
	LDRB R4,[R5],#1
  @LDR R16,[R5],#1
	MOV R0, R6
	BL displayBinary()
	MVN R0,R6
	BL leds
	MOV R0, #300
	BL delaysMillis
	SUBS R4,R4,#1
	BNE lopp
	POP(R4,R5,R6,PC) // Return

.data
array:
	.byte 0X80
	.byte 0X40
	.byte 0X20
	.byte 0X10
	.byte 0X08
	.byte 0X04
	.byte 0X02
	.byte 0X01
	.byte 0X02
	.byte 0X04
	.byte 0X08
	.byte 0X10
	.byte 0X20
	.byte 0X40
	.byte 0X80
.ends