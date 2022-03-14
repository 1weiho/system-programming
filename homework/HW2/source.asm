. Main function
	JSUB	INIT

. Array initialize
INIT	LDX	#0
	LDA	#1
	LDS	#3
	LDT	#30
ALOOP	STA	NUM,	X
	ADD	#1
	ADDR	S,	X
	COMPR	X,	T
	JLT	ALOOP
	RSUB

. Define variable
NUM	RESW	9