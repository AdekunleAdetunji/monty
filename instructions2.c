#include "monty.h"

/**
 * add - add first 2 elements on the stack and puts result in second element
 * pops the first element
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
		print_err("can't add, stack too short", line_number);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - subtracts 1st element fron 2nd on the stack and puts result in second
 * second element, then pops the first element
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
		print_err("can't sub, stack too short", line_number);

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
