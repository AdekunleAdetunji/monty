#include "monty.h"

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
		print_err("usage: push integer", line_number);

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

/**
 * pint - print the elements at the top of the stack
 * @stack: The address of the stack head node
 * @linenumber: The line number we are executing
 */
void pint(stack_t **stack, unsigned int linenumber)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
		print_err("can't pint, stack empty", linenumber);
}

/**
 * pop - remove the element at the top of a stack
 * @stack: The stack we desire to remove element from
 * @linenumber: The bytecode line number being executed
 */
void pop(stack_t **stack, unsigned int linenumber)
{
	stack_t *popped;

	if (!(*stack))
		print_err("can't pop an empty stack", linenumber);

	if (app.mode == 1)
		popped = delete_dnode_at_head(stack);
	else
		popped = delete_dnode_at_bottom(stack);
	free(popped);
}
/**
 * swap - swaps first 2 elements on the stack
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
