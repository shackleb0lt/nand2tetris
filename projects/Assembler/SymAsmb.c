#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



#define MAXLEN 20
#define MAXENT 1024
#define MAX_LINE_LEN 200


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



void symtab_add(struct table_entry item)
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



int con_sym(char *symbol) 
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



char *strip_comments_and_whitespace(char *s) {
	
	if (s == NULL) {
		return NULL;
	}
	else if (!*s) {
		return s;
	}

	char s_new[strlen(s) + 1];
	int i = 0;

	for (char *s2 = s; *s2; s2++) {
		if (*s2 == '/' && *(s2 + 1) == '/') {
			break;
		}
		else if (!isspace(*s2)) {
			s_new[i++] = *s2;
		}
	}
	s_new[i] = '\0';

	strcpy(s, s_new);

	return s;
}

bool is_label(const char *line, char *label)
{
	const char *s = line;
	const char *s_end = s + strlen(line) - 1;

	if (*s != '(') {
		return false;
	}
	if (*s_end != ')') {
		return false;
	}

	for (s = s + 1; s < s_end; s++) {
		if (*s == '(' || *s == ')') {
			return false;
		}
		*label++ = *s;
	}
	*label = '\0';

	return true;
}

/*
int main()
{
	InitSymbolTable();
	struct table_entry I1 = { "a",50 };
	struct table_entry I2 = { "b",-1 };
	struct table_entry I3 = { "c",52 };
	struct table_entry I4 = { "b",53 };
	struct table_entry I5 = { "e",54 };

	symtab_add(I1);
	symtab_add(I2);
	symtab_add(I3);
	symtab_add(I4);
	symtab_add(I5);
	Sym_Print();

}*/

int main(int argc, const char *argv[])
{
	

	/*
	 * Indicates number of current instruction.
	 * This counts only real instructions, not empty lines, comments nor labels.
	 */

	unsigned instruction_num = 0;

	/*
	 * Indicates current file line that is being processed.
	 */

	unsigned line_num = 0;

	/*
	 * Holds current instruction.
	 */
	generic_inst inst;

	/*
	 * A buffer keeping all valid instructions after reading them from the file.
	 */

	generic_inst *instructions = NULL;

	/*
	 * This indicates for how many instructions we have allocated memory.
	 * Initially we allocate INIT_MEMORY_ALLOC memory and later, whenever we
	 * hit this limit and need to store more instructions in memory we double
	 * this value.
	 */
	unsigned allocated_mem = 0;
	/*
	 * Holds current line read.
	 */
	char line[MAX_LINE_LEN + 1];
	char tmp_line[MAX_LINE_LEN + 1];

	/*
	 * Used to temporarily store the label of the current instruction, if
	 * the current instruction declares a new label.
	 */
	char label[MAX_LABEL_LEN + 1];

	FILE *fp = file_open_or_bail(argv[1], "r");

	SymbolTable symtab = symtab_init();
	populate_predefined_symbols(symtab);

	/* First pass */

	while (fgets(line, sizeof(line), fp)) {
		line_num++;
		if (instruction_num > MAX_INSTRUCTION) {
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTION + 1);
		}

		strip_comments_and_whitespace(line);

		if (!*line) {
			continue; // skip empty lines
		}

		if (is_label(line, label)) {
			if (!isalpha(*label)) {
				exit_program(EXIT_INVALID_LABEL, line_num, line);
			}
			if (symtab_lookup(symtab, label) != SYMBOL_NOT_FOUND) {
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
			}
			symtab_add(symtab, label, instruction_num);
			continue;
		}

		if (*line == '@') {
			if (!parse_A_instruction(line, &inst.inst.a)) {
				exit_program(EXIT_INVALID_A_INST, line_num, line);
			}
			inst.id = INST_A;
		}
		else {
			strcpy(tmp_line, line); // safe because they have same lengths
			parse_C_instruction(tmp_line, &inst.inst.c);

			if (inst.inst.c.dest == DEST_INVALID) {
				exit_program(EXIT_INVALID_C_DEST, line_num, line);
			}
			else if (inst.inst.c.comp == COMP_INVALID) {
				exit_program(EXIT_INVALID_C_COMP, line_num, line);
			}
			else if (inst.inst.c.jump == JMP_INVALID) {
				exit_program(EXIT_INVALID_C_JUMP, line_num, line);
			}

			inst.id = INST_C;
		}

		if (instruction_num == allocated_mem) {
			// We need more memory for storing instructions.
			// Double what we already have or make our first allocation of default value.
			unsigned tmp = allocated_mem ? allocated_mem * 2 : INIT_MEMORY_ALLOC;
			allocated_mem = tmp > MAX_INSTRUCTION ? MAX_INSTRUCTION : tmp;
			instructions = asm_realloc(instructions, allocated_mem * sizeof(generic_inst));
		}

		instructions[instruction_num++] = inst;
	}

	fclose(fp);

	// Reduce allocated memory to the amount of memory that we really need for
	// storing all instructions read.
	instructions = asm_realloc(instructions, instruction_num * sizeof(generic_inst));

	/* Second pass */

	opcode op;

	for (unsigned i = 0; i < instruction_num; i++) {
		op = 0;
		inst = instructions[i];

		if (inst.id == INST_A) {
			if (!inst.inst.a.resolved) {
				op = symtab_resolve(symtab, inst.inst.a.operand.symbol);
				free(inst.inst.a.operand.symbol);
			}
			else {
				op = inst.inst.a.operand.address;
			}
		}
		else if (inst.id == INST_C) {
			INST_TO_OPCODE(inst.inst.c, op);
		}

		printf(OPCODE_STR"\n", OPCODE_TO_BINARY(op));
	}


	return 0;
}

