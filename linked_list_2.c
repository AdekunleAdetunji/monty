#include "monty.h"

/**
 * print_dlistint - prints a double linked list of integers
 * @h: head node
 * Return: nunber of nodes
*/
size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}

	return (i);
}
/**
 * free_dlistint - frees a dlistint_t list.
 * @head: head node
*/
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
