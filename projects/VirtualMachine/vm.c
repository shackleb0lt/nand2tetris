#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define MAX_LINE_LEN 200
#define S_LEN 20
#define A_LEN 30

int get_index(char *s) 
{
	if (s == NULL || strlen(s) == 0) return -1;
	int sum = 0;
	char *s2;
	for (s2 = s; *s2; s2++) 
	{
		sum = sum * 10;
		sum += (int)(*s2);
		sum -= 48;
	}
	return sum;
}
int main(int argc, const char *argv[])
{
	char line[MAX_LINE_LEN];
	char sline[A_LEN];
	char Symbol1[S_LEN];
	char Symbol2[S_LEN];
	char Symbol3[S_LEN];
	FILE *filein;
	FILE *fileout;
	int ii,i, j, k,sec,type;
	int label_count = 0;
	filein = fopen(argv[1], "r");
	fileout = fopen(argv[2], "w");
	if (filein == NULL) printf("filein is null");
	if (fileout == NULL) printf("fileout is null");
	int fu = 0;
	while (fgets(line, MAX_LINE_LEN, filein) != NULL)
	{
		fu++;
		if (line == NULL)continue;
		else if (strlen(line) == 0) continue;
		ii = 0;
		sec = 1;
		i = 0;
		j = 0;
		k = 0;
		
		for (char *s2 = line; *s2; s2++) {
			if (*s2 == '/' && *(s2 + 1) == '/') break;

			else if (*s2!=' ') {
				if (sec == 1) 
				{
					Symbol1[i] = *s2;
					i++;
				}
				else if(sec == 2)
				{
					Symbol2[j] = *s2;
					j++;
				}
				else if(sec == 3)
				{
					Symbol3[k] = *s2;
					k++;
				}
			}
			else if (*s2!=' ') 
			{
				if (j == 0)sec = 2;
				else if (j != 0 && k == 0)sec = 3;
			}
		}
		Symbol1[i] = '\0';
		Symbol2[j] = '\0';
		Symbol3[k] = '\0';

		if (strlen(Symbol1) == 0) continue;
		fprintf(fileout,"//code for %s %s %s\n", Symbol1, Symbol2, Symbol3);
		printf("%s %s %s\n", Symbol1, Symbol2, Symbol3);
		//fprintf(fileout, "%s", line);
		//fprintf(fileout, "%s", "\n");
		
		if (strcmp(Symbol1, "add") == 0) 
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nM=M+D\n@SP\nM=M-1\n");
		}
		
		else if (strcmp(Symbol1, "sub") == 0) 
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nM=M-D\n@SP\nM=M-1\n");
		}

		else if (strcmp(Symbol1, "and") == 0)
		{
			
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nM=M&D\n@SP\nM=M-1\n");
		}

		else if (strcmp(Symbol1, "or") == 0)
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nM=M|D\n@SP\nM=M-1\n");
		}
		
		else if (strcmp(Symbol1, "not") == 0) 
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nM=!M\n");
		}

		else if (strcmp(Symbol1, "neg") == 0)
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nM=-M\n");
		}

		else if (strcmp(Symbol1, "eq") == 0) 
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nD=M-D\n");
			fprintf(fileout, "@ALABEL_%s_%d\n",argv[2],label_count);
			fprintf(fileout, "D;JEQ\n");
			fprintf(fileout, "D=0;\n");
			fprintf(fileout, "@ALABEL_%s_%d\n",argv[2], label_count + 1);
			fprintf(fileout, "0;JMP\n");
			fprintf(fileout, "(ALABEL_%s_%d)\n",argv[2],label_count);
			fprintf(fileout, "D=-1\n");
			fprintf(fileout, "(ALABEL_%s_%d)\n",argv[2],label_count + 1);
			fprintf(fileout, "@SP\nM=M-1\nA=M\nA=A-1\nM=D\n");
			label_count += 2;
		}

		else if (strcmp(Symbol1, "lt") == 0)
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nD=M-D\n");
			fprintf(fileout, "@ALABEL_%s_%d\n", argv[2], label_count);
			fprintf(fileout, "D;JLT\n");
			fprintf(fileout, "D=0;\n");
			fprintf(fileout, "@ALABEL_%s_%d\n", argv[2], label_count + 1);
			fprintf(fileout, "0;JMP\n");
			fprintf(fileout, "(ALABEL_%s_%d)\n", argv[2], label_count);
			fprintf(fileout, "D=-1\n");
			fprintf(fileout, "(ALABEL_%s_%d)\n",argv[2], label_count + 1);
			fprintf(fileout, "@SP\nM=M-1\nA=M\nA=A-1\nM=D\n");
			label_count += 2;
		}

		else if (strcmp(Symbol1, "gt") == 0)
		{
			fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\nA=A-1\nD=M-D\n");
			fprintf(fileout, "@ALABEL_%s_%d\n", argv[2], label_count);
			fprintf(fileout, "D;JGT\n");
			fprintf(fileout, "D=0;\n");
			fprintf(fileout, "@ALABEL_%s_%d\n", argv[2], label_count + 1);
			fprintf(fileout, "0;JMP\n");
			fprintf(fileout, "(ALABEL_%s_%d)\n", argv[2], label_count);
			fprintf(fileout, "D=-1\n");
			fprintf(fileout, "(ALABEL_%s_%d)\n", argv[2], label_count + 1);
			fprintf(fileout, "@SP\nM=M-1\nA=M\nA=A-1\nM=D\n");
			label_count += 2;
		}
		
		else if (strcmp(Symbol1, "push") == 0)
		{
			int e = get_index(Symbol3);
			if (strcmp(Symbol2, "constant") == 0)
			{
				fprintf(fileout, "@%s\n",Symbol3);
				fprintf(fileout, "D=A\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			}
			else if (strcmp(Symbol2, "argument") == 0) 
			{
				fprintf(fileout, "@ARG\n");
				fprintf(fileout, "D=M\n@%d\nA=A+D\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n",e);
			}
			else if (strcmp(Symbol2, "local") == 0) 
			{
				fprintf(fileout, "@LCL\n");
				fprintf(fileout, "D=M\n@%d\nA=A+D\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n", e);
			}
			else if (strcmp(Symbol2, "this") == 0)
			{
				fprintf(fileout, "@THIS\n");
				fprintf(fileout, "D=M\n@%d\nA=A+D\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n", e);
			}
			else if (strcmp(Symbol2, "that") == 0)
			{
				fprintf(fileout, "@THAT\n");
				fprintf(fileout, "D=M\n@%d\nA=A+D\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n", e);
			}
			else if (strcmp(Symbol2, "pointer") == 0) 
			{
				fprintf(fileout, "@3\nD=A\n@%d\nA=A+D\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n", e);
			}
			else if (strcmp(Symbol2, "temp") == 0)
			{
				fprintf(fileout, "@5\nD=A\n@%d\nA=A+D\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n", e);
			}
			else if (strcmp(Symbol2, "static") == 0) 
			{
				fprintf(fileout, "@%s.%d\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n", argv[2], e);
			}
			
		}
		else if (strcmp(Symbol1, "pop") == 0) 
		{
			int e = get_index(Symbol3);
			if (strcmp(Symbol2, "argument") == 0) 
			{
				fprintf(fileout, "@ARG\nD=M\n@%d\nD=A+D\n@R13\nM=D\n", e);
				fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\n@R13\nA=M\nM=D\n@SP\nM=M-1\n");
			}
			else if (strcmp(Symbol2, "local") == 0)
			{
				fprintf(fileout, "@LCL\nD=M\n@%d\nD=A+D\n@R13\nM=D\n", e);
				fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\n@R13\nA=M\nM=D\n@SP\nM=M-1\n");
			}
			else if (strcmp(Symbol2, "this") == 0)
			{
				fprintf(fileout, "@THIS\nD=M\n@%d\nD=A+D\n@R13\nM=D\n", e);
				fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\n@R13\nA=M\nM=D\n@SP\nM=M-1\n");
			}
			else if (strcmp(Symbol2, "that") == 0)
			{
				fprintf(fileout, "@THAT\nD=M\n@%d\nD=A+D\n@R13\nM=D\n", e);
				fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\n@R13\nA=M\nM=D\n@SP\nM=M-1\n");
			}
			else if (strcmp(Symbol2, "static") == 0) 
			{
				fprintf(fileout,"@SP\nA=M\nA=A-1\nD=M\n@%s.%d\nM=D\n@SP\nM=M-1\n",argv[2],e);
			}
			else if (strcmp(Symbol2, "temp") == 0) 
			{
				fprintf(fileout, "@5\nD=A\n@%d\nD=A+D\n@R13\nM=D\n",e);
				fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\n@R13\nA=M\nM=D\n@SP\nM=M-1\n");
			}
			else if (strcmp(Symbol2, "pointer") == 0) 
			{
				fprintf(fileout, "@3\nD=A\n@%d\nD=A+D\n@R13\nM=D\n", e);
				fprintf(fileout, "@SP\nA=M\nA=A-1\nD=M\n@R13\nA=M\nM=D\n@SP\nM=M-1\n");
			}
		}
		
		else if (strcmp(Symbol1, "label") == 0) 
		{
			fprintf(fileout,"(%s)\n",Symbol2);
		}
		else if (strcmp(Symbol1, "goto") == 0) 
		{
			fprintf(fileout, "@%s\n0;JMP\n", Symbol2);
		}
		else if (strcmp(Symbol1, "if-goto") == 0) 
		{
			fprintf(fileout,"@SP\nM=M-1\nA=M\nD=M\n@%s\nD;JNE\n",Symbol2);

		}
		
		else if (strcmp(Symbol1, "call")==0) 
		{
			fprintf(fileout, "//push return address\n");
			fprintf(fileout,"@CLBL_%s_%d\n",argv[2],label_count);
			fprintf(fileout, "D=A\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			fprintf(fileout, "//push local\n");
			fprintf(fileout, "@LCL\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			fprintf(fileout, "//push argument\n");
			fprintf(fileout, "@ARG\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			fprintf(fileout, "//push this\n");
			fprintf(fileout, "@THIS\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			fprintf(fileout, "//push that\n");
			fprintf(fileout, "@THAT\nD=M\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			fprintf(fileout, "//ARG=SP-N-5\n");
			fprintf(fileout, "@SP\nD=M\n");
			fprintf(fileout, "@%s\nD=D-A\n@5\nD=D-A\n@ARG\nM=D\n", Symbol3);
			fprintf(fileout, "//LCL=SP\n");
			fprintf(fileout, "@SP\nD=M\n@LCL\nM=D\n");
			fprintf(fileout, "//go to function\n");
			fprintf(fileout, "@%s \n0;JMP\n",Symbol2);
			fprintf(fileout, "//return address\n");
			fprintf(fileout, "(CLBL_%s_%d)\n",argv[2],label_count);
			label_count++;
		}
		else if (strcmp(Symbol1,"return")== 0)
		{
			fprintf(fileout, "@LCL\nD=M\n@R13\nM=D\n");
			fprintf(fileout, "//RET= *FRAME-5\n");
			fprintf(fileout, "@5\nA=D-A\nD=M\n@R14\nM=D\n");
			fprintf(fileout, "//R14 has return address\n");
			fprintf(fileout, "@SP\nM=M-1\nA=M\nD=M\n@ARG\nA=M\nM=D\n");
			fprintf(fileout, "//SP=ARG+1\n");
			fprintf(fileout, "@ARG\nD=M\nD=D+1\n@SP\nM=D\n");
			fprintf(fileout, "//THAT=*FRAME-1\n");
			fprintf(fileout, "@R13\nM=M-1\nA=M\nD=M\n@THAT\nM=D\n");
			fprintf(fileout, "//THIS=*FRAME-2\n");
			fprintf(fileout, "@R13\nM=M-1\nA=M\nD=M\n@THIS\nM=D\n");
			fprintf(fileout, "//ARG=*FRAME-3\n");
			fprintf(fileout, "@R13\nM=M-1\nA=M\nD=M\n@ARG\nM=D\n");
			fprintf(fileout, "//LCL=*FRAME-4\n");
			fprintf(fileout, "@R13\nM=M-1\nA=M\nD=M\n@LCL\nM=D\n");
			fprintf(fileout, "@R14\nA=M\n0;JMP\n");
		}
		else if (strcmp(Symbol1, "function") == 0) 
		{
			int e = get_index(Symbol3);
			fprintf(fileout, "(%s)\n",Symbol2);
			fprintf(fileout, "//pushing 0 k times\n");
			int k;
			for (k = 0; k < e; k++) 
			{
				fprintf(fileout, "@0\n");
				fprintf(fileout, "D=A\n@SP\nA=M\nM=D\n@SP\nM=M+1\n");
			}
		}
	}

}
