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

@3000
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
//code for function Main.fibonacci 0
(Main.fibonacci)
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
//code for push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for lt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_Main.asm_0
D;JLT
D=0;
@ALABEL_Main.asm_1
0;JMP
(ALABEL_Main.asm_0)
D=-1
(ALABEL_1)
@SP
M=M-1
A=M
A=A-1
M=D
//code for if-goto IF_TRUE 
@SP
M=M-1
A=M
D=M
@IF_TRUE
D;JNE
//code for goto IF_FALSE 
@IF_FALSE
0;JMP
//code for label IF_TRUE 
(IF_TRUE)
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
//code for label IF_FALSE 
(IF_FALSE)
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
//code for call Main.fibonacci 1
//push return address
@CLBL_Main.asm_2
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
(CLBL_Main.asm_2)
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
//code for call Main.fibonacci 1
//push return address
@CLBL_Main.asm_3
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
(CLBL_Main.asm_3)
//code for add  
@SP
A=M
A=A-1
D=M
A=A-1
M=M+D
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
