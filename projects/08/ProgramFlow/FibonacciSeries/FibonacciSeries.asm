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
//code for pop pointer 1
@3
D=A
@1
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
//code for push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for pop that 0
@THAT
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
//code for push constant 1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for pop that 1
@THAT
D=M
@1
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
//code for push constant 2
@2
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
//code for label MAIN_LOOP_START 
(MAIN_LOOP_START)
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
//code for if-goto COMPUTE_ELEMENT 
@SP
M=M-1
A=M
D=M
@COMPUTE_ELEMENT
D;JNE
//code for goto END_PROGRAM 
@END_PROGRAM
0;JMP
//code for label COMPUTE_ELEMENT 
(COMPUTE_ELEMENT)
//code for push that 0
@THAT
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for push that 1
@THAT
D=M
@1
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
//code for pop that 2
@THAT
D=M
@2
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
//code for push pointer 1
@3
D=A
@1
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
//code for add  
@SP
A=M
A=A-1
D=M
A=A-1
M=M+D
@SP
M=M-1
//code for pop pointer 1
@3
D=A
@1
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
//code for goto MAIN_LOOP_START 
@MAIN_LOOP_START
0;JMP
//code for label END_PROGRAM 
(END_PROGRAM)
