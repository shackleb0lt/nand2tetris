//code for push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for pop local 0
@LCL
D=M
@0
D=A+D
@R13
M=D
@SP
A=M
A=A-1
D=M
@R13
A=M
M=D
@SP
M=M-1
//code for label LOOP_START 
(LOOP_START)
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
//code for push local 0
@LCL
D=M
@0
A=A+D
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
//code for pop local 0
@LCL
D=M
@0
D=A+D
@R13
M=D
@SP
A=M
A=A-1
D=M
@R13
A=M
M=D
@SP
M=M-1
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
//code for push constant 1
@1
D=A
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
//code for pop argument 0
@ARG
D=M
@0
D=A+D
@R13
M=D
@SP
A=M
A=A-1
D=M
@R13
A=M
M=D
@SP
M=M-1
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
//code for if-goto LOOP_START 
@SP
M=M-1
A=M
D=M
@LOOP_START
D;JNE
//code for push local 0
@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
