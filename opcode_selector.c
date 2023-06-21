#include "monty.h"
/**
 * select_inst - selects the function of opcode
 * @code: opcode from the line of file (should be args[0])
 * Return: function of opcode if found, else NULL
*/

void (*select_inst(char *code))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (instruction[i].opcode && strcmp(code, instruction[i].opcode) != 0)
		i++;
	return (instruction[i].f);
}
