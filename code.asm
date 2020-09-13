Mini projet compile 'R language'
Pile segment stack
	DW 6 dup(?)
Pile ends
DATA segment
	B DW ?
	X DW ?
	T DW ?
	A DW ?
DATA ends
CODE segment
	MAIN:
		ASSUME CS:CODE, DS:DATA, SS:Pile
		MOV AX, data
		MOV DS, AX
		MOV AX, Pile
		MOV SS, AX
		;Quad(=, 0, , T)
		MOV T, 0
		;Quad(+, 7, 7, t01)
		MOV AX, 7
		ADD AX, 7
		MOV SP, 2
		PUSH AX
		;Quad(=, t01, , A)
		MOV SP, 0
		POP AX
		MOV A, AX
		;Quad(=, 0, , X)
		MOV X, 0
	etiq04:
		;Quad(BG, 10, X, 1)
		MOV SP, -2
		POP CX
		CMP 10, CX
		JG etiq10
		;Quad(+, A, 1, t02)
		MOV AX, A
		ADD AX, 1
		MOV SP, 4
		PUSH AX
		;Quad(=, t02, , A)
		MOV SP, 2
		POP AX
		MOV A, AX
		;Quad(+, X, 1, t03)
		MOV AX, X
		ADD AX, 1
		MOV SP, 6
		PUSH AX
		;Quad(=, t03, , X)
		MOV SP, 4
		POP AX
		MOV X, AX
		;Quad(BR, 04, , )
		  JMP etiq04
	etiq10:
		;Quad(BNE, 18, A, 1)
		MOV SP, -2
		POP CX
		CMP 18, CX
		JNE etiq18
		;Quad(BNE, 17, 1, 1)
		MOV CX, 1
		MOV SP, -2
		POP BX
		CMP CX, BX
		JNE etiq17
		;Quad(BLE, 15, 1, 2)
		MOV CX, 1
		MOV SP, -2
		POP BX
		CMP CX, BX
		JLE etiq15
		;Quad(=, B, , A)
		MOV AX, B
		MOV A, AX
		;Quad(BR, 17, , )
		  JMP etiq17
	etiq15:
		;Quad(+, 3, t01, t04)
		MOV AX, 3
		MOV SP, 0
		POP BX
		ADD AX, BX
		MOV SP, 8
		PUSH AX
		;Quad(=, t04, , A)
		MOV SP, 6
		POP AX
		MOV A, AX
	etiq17:
		;Quad(BR, 10, , )
		  JMP etiq10
	etiq18:
		ENDS
	END MAIN
