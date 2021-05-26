//code for function Sys.init 0
(Sys.init)
//pushing 0 k times
//code for push constant 4
@4
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for call Main.fibonacci 1
//push return address
@CLBL_Sys.asm_0
D=A
@SP
A=M
M=D
@SP
M=M+1
//push local
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
//push argument
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
//push this
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
//push that
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
//ARG=SP-N-5
@SP
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
//LCL=SP
@SP
D=M
@LCL
M=D
//go to function
@Main.fibonacci 
0;JMP
//return address
(CLBL_Sys.asm_0)
//code for label WHILE 
(WHILE)
//code for goto WHILE 
@WHILE
0;JMP
