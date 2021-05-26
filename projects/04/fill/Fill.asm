// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


(READ_INPUT)
	@KBD
	D=M

	@color
	M=0

	@FILL_SCREEN
	D;JEQ // if keyboard = 0, goto FILL_SCREEN

	@DARKEN
	0;JMP // else, goto DARKEN
@READ_INPUT
0;JMP

(DARKEN)
@color
M=-1
@FILL_SCREEN
0;JMP

(FILL_SCREEN)


	@SCREEN
	D=A
	@i
	M=D 

	(FILL_LOOP)
		@color
		D=M
		@i
		A=M
		M=D // MEM[i]= color

		@i
		M=M+1 // i+= 1

		@24576 
		D=A
		@i
		D=D-M // D = 24576 -i
	
	@FILL_LOOP
	D;JGT // if D > 0 goto FILL_LOOP

@READ_INPUT
0;JMP