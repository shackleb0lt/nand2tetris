@256
D=A
@SP
M=D

@400
D=A
@LCL
M=D

@500
D=A
@ARG
M=D

@300
D=A
@THIS
M=D

@4000
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
//code for function Class2.set 0
(Class2.set)
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
@Class2.asm.0
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
@Class2.asm.1
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
//code for function Class2.get 0
(Class2.get)
//pushing 0 k times
//code for push static 0
@Class2.asm.0
D=M
@SP
A=M
M=D
@SP
M=M+1
//code for push static 1
@Class2.asm.1
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
