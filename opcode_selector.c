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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	while (instruction[i].opcode && strcmp(code, instruction[i].opcode) != 0)
		i++;
	return (instruction[i].f);
}
