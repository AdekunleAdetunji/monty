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

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		print_err("can't pchar, stack empty", line_number);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		print_err("can't pchar, value out of range", line_number);
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp && tmp->n > 0 && tmp->n < 127)
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top.
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = app.bottom;
		app.bottom->next = tmp;
		app.bottom = tmp;
	}
}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: The stack we are pushing untop
 * @line_number: The line number we are reading from
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (*stack && (*stack)->next)
	{
		tmp = app.bottom;
		app.bottom = tmp->prev;
		app.bottom->next = NULL;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}
