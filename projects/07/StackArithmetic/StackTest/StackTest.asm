//code for push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for eq  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_0
D;JEQ
D=0;
@ALABEL_1
0;JMP
(ALABEL_0)
D=-1
(ALABEL_1)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 16
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for eq  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_2
D;JEQ
D=0;
@ALABEL_3
0;JMP
(ALABEL_2)
D=-1
(ALABEL_3)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 16
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for eq  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_4
D;JEQ
D=0;
@ALABEL_5
0;JMP
(ALABEL_4)
D=-1
(ALABEL_5)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 892
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 891
@891
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
@ALABEL_6
D;JLT
D=0;
@ALABEL_7
0;JMP
(ALABEL_6)
D=-1
(ALABEL_7)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 892
@892
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
@ALABEL_8
D;JLT
D=0;
@ALABEL_9
0;JMP
(ALABEL_8)
D=-1
(ALABEL_9)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 891
@891
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
@ALABEL_10
D;JLT
D=0;
@ALABEL_11
0;JMP
(ALABEL_10)
D=-1
(ALABEL_11)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 32767
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for gt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_12
D;JGT
D=0;
@ALABEL_13
0;JMP
(ALABEL_12)
D=-1
(ALABEL_13)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 32767
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for gt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_14
D;JGT
D=0;
@ALABEL_15
0;JMP
(ALABEL_14)
D=-1
(ALABEL_15)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for gt  
@SP
A=M
A=A-1
D=M
A=A-1
D=M-D
@ALABEL_16
D;JGT
D=0;
@ALABEL_17
0;JMP
(ALABEL_16)
D=-1
(ALABEL_17)
@SP
M=M-1
A=M
A=A-1
M=D
//code for push constant 57
@57
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 31
@31
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for push constant 53
@53
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
//code for push constant 112
@112
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
//code for neg  
@SP
A=M
A=A-1
M=-M
//code for and  
@SP
A=M
A=A-1
D=M
A=A-1
M=M&D
@SP
M=M-1
//code for push constant 82
@82
D=A
@SP
A=M
M=D
@SP
M=M+1
//code for or  
@SP
A=M
A=A-1
D=M
A=A-1
M=M|D
@SP
M=M-1
//code for not  
@SP
A=M
A=A-1
M=!M
