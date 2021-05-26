//code for function Sys.init 0
(Sys.init)
//pushing 0 k times
//code for push constant 6
@6
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 8
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for call Class1.set 2
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
@2
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
@Class1.set 
0;JMP
//return address
(CLBL_Sys.asm_0)
//code for pop temp 0
@5
D=A
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
//code for push constant 23
@23
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 15
@15
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for call Class2.set 2
//push return address
@CLBL_Sys.asm_1
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
@2
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
@Class2.set 
0;JMP
//return address
(CLBL_Sys.asm_1)
//code for pop temp 0
@5
D=A
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
//code for call Class1.get 0
//push return address
@CLBL_Sys.asm_2
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
@Class1.get 
0;JMP
//return address
(CLBL_Sys.asm_2)
//code for call Class2.get 0
//push return address
@CLBL_Sys.asm_3
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
@Class2.get 
0;JMP
//return address
(CLBL_Sys.asm_3)
//code for label WHILE 
(WHILE)
//code for goto WHILE 
@WHILE
0;JMP
