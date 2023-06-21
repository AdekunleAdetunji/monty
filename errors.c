#include "monty.h"

/**
 * monty_usage_err - prints usage error for monty app
*/

void monty_usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * monty_file_err - prints file opening error
 * @file_name: file name
*/

void monty_file_err(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

/**
 * instructions_err - prints file opening error
 * @l_num: file line number
 * @inst: unknown instruction
*/

void instructions_err(int l_num, char *inst)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", l_num, inst);
	free_app();
	exit(EXIT_FAILURE);
}
/**
 * pop_err - error of pop
 * @l_num: line number
*/
void pop_err(int l_num)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
	exit(EXIT_FAILURE);
}
