#include "monty.h"
/**
 * mod - modulo 2nd element by 1st on the stack and puts result in
 * second element, then pops the first element
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !((*stack)->next))
		print_err("can't mod, stack too short", line_number);
	if ((*stack)->n == 0)
		print_err("division by zero", line_number);
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
