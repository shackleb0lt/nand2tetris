//code for function Class1.set 0
(Class1.set)
//pushing 0 k times
//code for push argument 0
@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for pop static 0
@SP
A=M
A=A-1
D=M
@Class1.asm.0
M=D
@SP
M=M-1
//code for push argument 1
@ARG
D=M
@1
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for pop static 1
@SP
A=M
A=A-1
D=M
@Class1.asm.1
M=D
@SP
M=M-1
//code for push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for return  
@LCL
D=M
@R13
M=D
//RET= *FRAME-5
@5
A=D-A
D=M
@R14
M=D
//R14 has return address
@SP
M=M-1
A=M
D=M
@ARG
A=M
M=D
//SP=ARG+1
@ARG
D=M
D=D+1
@SP
M=D
//THAT=*FRAME-1
@R13
M=M-1
A=M
D=M
@THAT
M=D
//THIS=*FRAME-2
@R13
M=M-1
A=M
D=M
@THIS
M=D
//ARG=*FRAME-3
@R13
M=M-1
A=M
D=M
@ARG
M=D
//LCL=*FRAME-4
@R13
M=M-1
A=M
D=M
@LCL
M=D
@R14
A=M
0;JMP
//code for function Class1.get 0
(Class1.get)
//pushing 0 k times
//code for push static 0
@Class1.asm.0
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for push static 1
@Class1.asm.1
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for sub  
@SP
A=M
A=A-1
D=M
A=A-1
M=M-D
@SP
M=M-1
//code for return  
@LCL
D=M
@R13
M=D
//RET= *FRAME-5
@5
A=D-A
D=M
@R14
M=D
//R14 has return address
@SP
M=M-1
A=M
D=M
@ARG
A=M
M=D
//SP=ARG+1
@ARG
D=M
D=D+1
@SP
M=D
//THAT=*FRAME-1
@R13
M=M-1
A=M
D=M
@THAT
M=D
//THIS=*FRAME-2
@R13
M=M-1
A=M
D=M
@THIS
M=D
//ARG=*FRAME-3
@R13
M=M-1
A=M
D=M
@ARG
M=D
//LCL=*FRAME-4
@R13
M=M-1
A=M
D=M
@LCL
M=D
@R14
A=M
0;JMP
