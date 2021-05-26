#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



#define MAXLEN 20
#define MAXENT 1024
#define MAX_LINE_LEN 200
#define LEN 17

struct table_entry {

	char symbol[MAXLEN];
	int address;
};


struct table_entry SymbolTable[MAXENT];

void InitSymbolTable()
{
	strcpy(SymbolTable[0].symbol, "SP");
	strcpy(SymbolTable[1].symbol, "LCL");
	strcpy(SymbolTable[2].symbol, "ARG");
	strcpy(SymbolTable[3].symbol, "THIS");
	strcpy(SymbolTable[4].symbol, "THAT");
	strcpy(SymbolTable[5].symbol, "R0");
	strcpy(SymbolTable[6].symbol, "R1");
	strcpy(SymbolTable[7].symbol, "R2");
	strcpy(SymbolTable[8].symbol, "R3");
	strcpy(SymbolTable[9].symbol, "R4");
	strcpy(SymbolTable[10].symbol, "R5");
	strcpy(SymbolTable[11].symbol, "R6");
	strcpy(SymbolTable[12].symbol, "R7");
	strcpy(SymbolTable[13].symbol, "R8");
	strcpy(SymbolTable[14].symbol, "R9");
	strcpy(SymbolTable[15].symbol, "R10");
	strcpy(SymbolTable[16].symbol, "R11");
	strcpy(SymbolTable[17].symbol, "R12");
	strcpy(SymbolTable[18].symbol, "R13");
	strcpy(SymbolTable[19].symbol, "R14");
	strcpy(SymbolTable[20].symbol, "R15");
	strcpy(SymbolTable[21].symbol, "SCREEN");
	strcpy(SymbolTable[22].symbol, "KBD");

	SymbolTable[0].address = 0;
	SymbolTable[1].address = 1;
	SymbolTable[2].address = 2;
	SymbolTable[3].address = 3;
	SymbolTable[4].address = 4;
	SymbolTable[5].address = 0;
	SymbolTable[6].address = 1;
	SymbolTable[7].address = 2;
	SymbolTable[8].address = 3;
	SymbolTable[9].address = 4;
	SymbolTable[10].address = 5;
	SymbolTable[11].address = 6;
	SymbolTable[12].address = 7;
	SymbolTable[13].address = 8;
	SymbolTable[14].address = 9;
	SymbolTable[15].address = 10;
	SymbolTable[16].address = 11;
	SymbolTable[17].address = 12;
	SymbolTable[18].address = 13;
	SymbolTable[19].address = 14;
	SymbolTable[20].address = 15;
	SymbolTable[21].address = 16384;
	SymbolTable[22].address = 24576;
	for (int i = 23; i < MAXENT; i++)
	{
		strcpy(SymbolTable[i].symbol, "\0");
		SymbolTable[i].address = -1;
	}
}



void addEntry(struct table_entry item)
{

	int i = 0;
	while (strcmp(SymbolTable[i].symbol, item.symbol) != 0 && strcmp(SymbolTable[i].symbol, "\0") != 0 && i < MAXENT) i++;

	if (strcmp(SymbolTable[i].symbol, "\0") == 0)
	{
		strcpy(SymbolTable[i].symbol, item.symbol);
		SymbolTable[i].address = item.address;
	}
	if (strcmp(SymbolTable[i].symbol, item.symbol) == 0 && SymbolTable[i].address == -1)
	{
		SymbolTable[i].address = item.address;
	}
	if (i > MAXENT) printf("SYMBOL TABLE IS FULL, INCREASE THE MAXENTRIES LIMIT");

}



int contains(char *symbol)
{
	int i = 0;
	while (i < MAXENT && SymbolTable[i].address == -1)
	{
		if (strcmp(SymbolTable[i].symbol, symbol) == 0) return SymbolTable[i].address;
		i++;
	}
	return -1;
}


void Sym_Print()
{
	int i = 0;
	while (SymbolTable[i].address != -1 && i < MAXENT)
	{
		printf("%s %d \n", SymbolTable[i].symbol, SymbolTable[i].address);
		i++;
	}
}


int strip_comments_and_whitespace(char *s, char *s1) {

	if (s == NULL) {
		return 0;
	}
	
	else if (strlen(s)==0) return 0;
	int i = 0;
	
	for (char *s2 = s; *s2; s2++) {
		if (*s2 == '/' && *(s2 + 1) == '/') {
			break;
		}
		else if (!isspace(*s2)) {
			s1[i] = *s2;
			i++;
		}
	}
	s1[i] = '\0';
	if (strlen(s1) == 0) return 0;
	
	return 1;
}

int is_label(const char *line, char *label)
{
	const char *s = line;
	const char *s_end = s + strlen(line) - 1;	
	if (*s == '(' && *s_end == ')')
	{
		for (s = s + 1; s < s_end; s++) {
			*label = *s;
			label++;
		}
		*label = '\0';
		return 1;
	}
	return 0;
}

char inst_type(char *line,int *value,int *mem) 
{
	char *s = line;
	int ascii,j;
	if (*s == '@') 
	{ 
		bool flag = true;
		for (char *s1 = s + 1; *(s1+1)!='\0'; s1++)
		{
			if (*s1 < 48 || *s1 > 57) 
			{
				flag = false;
				break;
			}
			ascii = (int)*s1;
			(*value) *= 10;
			(*value) += ascii - 48;
			

		}
		if (flag == true) return 'a';
		else if (flag == false) 
		{
			int i = 0;
			char att[15];
			for (char *s = line + 1; *s != '\n'; s++) 
			{
				att[i] = *s;
				i++;
			}
			att[i] = '\0';
			//printf("%s",att);
			j=contains(att);

			if (j == -1) 
			{
				struct table_entry New;
				New.address = *mem;
				strcpy(New.symbol, line + 1);
				addEntry(New);
				*value = *mem;
				(*mem)++;
			}
			else *value = j;

			return 'A';
		}
	}
	return 'C';
}


int Bin(int n, int j, char * value) 
{
	if (n == 0) return 1;
	else Bin(n / 2, j -1, value);
	if (n % 2 == 0) value[j] = '0';
	if (n % 2 == 1) value[j] = '1';
	return 1;
}


int main(int argc,const char *argv[]) 
{
	char line[MAX_LINE_LEN];
	char sline[MAX_LINE_LEN];
	FILE *file;
	FILE *file1;
	int i, j, k;
	int curr_inst = 0;

	char lbl[MAXLEN];

	InitSymbolTable();

	/*
	*Strips the file of whitespaces and comments and 
	*saves ina file with .inter extension
	*/
	file = fopen(argv[1],"r");
	file1 = fopen(argv[2], "w");
	if(file==NULL) printf("file is null");
	if(file1==NULL) printf("file1 is null");

	
;	while (fgets(line, MAX_LINE_LEN, file)!=NULL)
	{
		
		i=strip_comments_and_whitespace(line,sline);
		if (i == 1)
		{
			j = is_label(sline, lbl);
			if (j == 1)
			{
				struct table_entry Entry;
				Entry.address = curr_inst;
				strcpy(Entry.symbol, lbl);
				addEntry(Entry);
			}
			if (j == 0) 
			{
				curr_inst++;
				fprintf(file1, "%s", sline);
				fprintf(file1, "%s", "\n");
			}
		}

	}
	
	
	fclose(file);
	fclose(file1);

	file = fopen(argv[2], "r");
	file1 = fopen(argv[3], "w");
	char inpline[15];
	curr_inst=0;
	int curr_add = 16;
	char inst;
	char value[LEN];
	value[16] = '\0';
 
	
	while (fgets(inpline, 15, file) != NULL) 
	{
		if (strlen(inpline) != 0) {
			k = 0;
			for (i = 0; i < 16; i++) value[i] = '0';

			inst = inst_type(inpline,&k,&curr_add);;
			printf("%c", inst);
			if (inst == 'a') 
			{
				if (k > 24576) printf("Memory out of index");
				Bin(k,15,value);
				value[0] = '0';
				
				
			}
			if (inst == 'A') 
			{
				for (i = 0; i < 16; i++) value[i] = '0';
				Bin(k, 15, value);
			}

			
			if (inst == 'C') 
			{				
				int i = 0;
				char inpdest[10];
				char inpcomp[10];
				char inpjmp[10];
				for (int i = 0; i < 3; i++)value[i] = '1';
				i = 0;
				while (inpline[i] != '\0')
				{
					if (inpline[i] == '=') break;
					else if (inpline[i] == ';') break;
					inpdest[i] = inpline[i];
					inpcomp[i] = inpline[i];				
					i++;
				}
				k = 0;
				if (inpline[i] == '=')
				{
					inpdest[i] = '\0';
					i++;
					while (inpline[i] != '\0')
					{
						inpcomp[k] = inpline[i];
						i++;
						k++;
					}
					inpcomp[k] = '\0';
					value[15] = '0';
					value[14] = '0';
					value[13] = '0';
					inpjmp[0] = '\0';

					if (strcmp(inpdest, "M") == 0) { value[10] = '0'; value[11] = '0'; value[12] = '1'; }
					else if(strcmp(inpdest,"D") == 0) { value[10] = '0'; value[11] = '1'; value[12] = '0'; }
					else if (strcmp(inpdest, "MD") == 0) { value[10] = '0'; value[11] = '1'; value[12] = '1'; }
					else if (strcmp(inpdest, "A") == 0) { value[10] = '1'; value[11] = '0'; value[12] = '0'; }
					else if (strcmp(inpdest, "AM") == 0) { value[10] = '1'; value[11] = '0'; value[12] = '1'; }
					else if (strcmp(inpdest, "AD") == 0) { value[10] = '1'; value[11] = '1'; value[12] = '0'; }
					else if (strcmp(inpdest, "AMD") == 0) { value[10] = '1'; value[11] = '1'; value[12] = '1'; }
				}
				k = 0;
				if (inpline[i] == ';')
				{
					inpdest[0] = '\0';
					inpcomp[i] = '\0';
					i++;
					while (inpline[i] != '\0')
					{
						inpjmp[k] = inpline[i];
						i++;
						k++;
					}
					inpjmp[k] = '\0';
					value[12] = '0';
					value[11] = '0';
					value[10] = '0';

					if (strcmp(inpjmp, "JGT") == 0) { value[13] = '0'; value[14] = '0'; value[15] = '1';}
					else if (strcmp(inpjmp, "JEQ") == 0) { value[13] = '0'; value[14] = '1'; value[15] = '0'; }
					else if (strcmp(inpjmp, "JGE") == 0) { value[13] = '0'; value[14] = '1'; value[15] = '1'; }
					else if (strcmp(inpjmp, "JLT") == 0) { value[13] = '1'; value[14] = '0'; value[15] = '0'; }
					else if (strcmp(inpjmp, "JNE") == 0) { value[13] = '1'; value[14] = '0'; value[15] = '1'; }
					else if (strcmp(inpjmp, "JLE") == 0) { value[13] = '1'; value[14] = '1'; value[15] = '0'; }
					else if (strcmp(inpjmp, "JMP") == 0) { value[13] = '1'; value[14] = '1'; value[15] = '1'; }
				}
				if (strcmp(inpcomp, "0") == 0) 
				{ value[3] = '0'; value[4] = '1'; value[5] = '0'; value[6] = '1'; value[7] = '0'; value[8] = '1'; value[9] = '0';}
				
				else if (strcmp(inpcomp, "1") == 0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '1'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "-1") == 0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '1'; value[7] = '0'; value[8] = '1'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D") == 0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '1'; value[7] = '1'; value[8] = '0'; value[9] = '0'; }

				else if (strcmp(inpcomp, "A") == 0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '0'; value[9] = '0'; }

				else if (strcmp(inpcomp, "!D") == 0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '1'; value[7] = '1'; value[8] = '0'; value[9] = '1'; }

				else if (strcmp(inpcomp, "!A") == 0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '0'; value[9] = '1'; }

				else if (strcmp(inpcomp, "-D") == 0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '1'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "-A") == 0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '1'; }
				
				else if (strcmp(inpcomp, "D+1") == 0 || strcmp(inpcomp,"1+D")==0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '1'; value[6] = '1'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "A+1") == 0 || strcmp(inpcomp,"1+A")==0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "D-1") == 0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '1'; value[7] = '1'; value[8] = '1'; value[9] = '0'; }

				else if (strcmp(inpcomp, "A-1") == 0)
				{ value[3] = '0'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D+A") == 0 || strcmp(inpcomp,"A+D")==0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D-A") == 0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "A-D") == 0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '0'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "D&A") == 0 || strcmp(inpcomp,"A&D")==0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '0'; value[6] = '0'; value[7] = '0'; value[8] = '0'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D|A") == 0 || strcmp(inpcomp,"A|D")==0)
				{ value[3] = '0'; value[4] = '0'; value[5] = '1'; value[6] = '0'; value[7] = '1'; value[8] = '0'; value[9] = '1'; }

				else if (strcmp(inpcomp, "M") == 0)
				{ value[3] = '1'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '0'; value[9] = '0'; }

				else if (strcmp(inpcomp, "!M") == 0)
				{ value[3] = '1'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '0'; value[9] = '1'; }

				else if (strcmp(inpcomp, "-M") == 0)
				{ value[3] = '1'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "M+1") == 0 || strcmp(inpcomp,"1+M")==0)
				{ value[3] = '1'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "M-1") == 0)
				{ value[3] = '1'; value[4] = '1'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D+M") == 0 || strcmp(inpcomp,"M+D")==0)
				{ value[3] = '1'; value[4] = '0'; value[5] = '0'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D-M") == 0)
				{ value[3] = '1'; value[4] = '0'; value[5] = '1'; value[6] = '0'; value[7] = '0'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "M-D") == 0)
				{ value[3] = '1'; value[4] = '0'; value[5] = '0'; value[6] = '0'; value[7] = '1'; value[8] = '1'; value[9] = '1'; }

				else if (strcmp(inpcomp, "D&M") == 0 || strcmp(inpcomp,"M&D")==0)
				{ value[3] = '1'; value[4] = '0'; value[5] = '0'; value[6] = '0'; value[7] = '0'; value[8] = '0'; value[9] = '0'; }

				else if (strcmp(inpcomp, "D|M") == 0 || strcmp(inpcomp,"M|D"))
				{ value[3] = '1'; value[4] = '0'; value[5] = '1'; value[6] = '0'; value[7] = '1'; value[8] = '0'; value[9] = '1'; }
				

			}
			
			fprintf(file1, "%s", value);
			fprintf(file1, "%s", "\n");
			
		}
	}
	Sym_Print();
	fclose(file);
	return 0;
	
}