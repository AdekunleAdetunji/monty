#include "monty.h"

/**
 * len - check for the length of an array
 * @argv: The vector under consideration
 * Return: Number of argument
 */
int len(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
	}

	return (i);
}

/**
 * push - push unto the stack
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void push(stack_t **stack, unsigned int line_number)
{
	int opcode;
	char **argv = app.args, *endptr;

	if (len(argv) < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_app();
		exit(EXIT_FAILURE);
	}

	opcode = (int) strtol(argv[1], &endptr, 10);
	if (strlen(endptr))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_app();
		exit(EXIT_FAILURE);
	}

	if (app.mode == 1)
	{
		app.top = add_dnodeint(stack, opcode);
		if (line_number == 1)
			app.bottom = app.top;
	}
	else
		app.bottom = add_dnodeint_end(stack, opcode);
}

/**
 * pall - print the elements of a stack
 * @stack: The address of the stack head node
 * @linenumber: The line number we are printing
 */
void pall(stack_t **stack, unsigned int linenumber)
{
	(void) linenumber;

	print_dlistint(*stack);
}
