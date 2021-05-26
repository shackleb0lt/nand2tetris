@256
D=A
@SP
M=D

@-1
D=A
@LCL
M=D

@-2
D=A
@ARG
M=D

@-3
D=A
@THIS
M=D

@-4
D=A
@THAT
M=D
//code for call Sys.init 0
//push return address
@CLBL_BootStrap.asm_0
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
@0
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
@Sys.init 
0;JMP
//return address
(CLBL_BootStrap.asm_0)
