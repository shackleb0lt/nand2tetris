//code for push constant 111
@111
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 333
@333
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 888
@888
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for pop static 8
@SP
A=M
A=A-1
D=M
@StaticTest.asm.8
M=D
@SP
M=M-1
//code for pop static 3
@SP
A=M
A=A-1
D=M
@StaticTest.asm.3
M=D
@SP
M=M-1
//code for pop static 1
@SP
A=M
A=A-1
D=M
@StaticTest.asm.1
M=D
@SP
M=M-1
//code for push static 3
@StaticTest.asm.3
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for push static 1
@StaticTest.asm.1
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
//code for push static 8
@StaticTest.asm.8
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for add  
@SP
A=M
A=A-1
D=M
A=A-1
M=M+D
@SP
M=M-1
