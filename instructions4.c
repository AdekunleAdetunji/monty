#include "monty.h"

/**
 * queue - switch mode to queue mode
 * @stack: The instruction stack
 * @line_number: The line number of instruction beign executed
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	app.mode = 0;
}

/**
 * stack - switch mode back to stack mode
 * @stack: The instruction stack
 * @line_number: The line number of the instruction being exectuted
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	app.mode = 1;
}
