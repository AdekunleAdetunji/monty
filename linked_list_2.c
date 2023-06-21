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

/**
 * rotate_dlint - rotates the entire double linked list
 * @head: pointer to head node
 * Return: pointer to the bottom of the node;
*/
stack_t *rotate_dlint(stack_t **head)
{
	stack_t *prev_head, *temp, *temp1, *temp2, *h;

	prev_head = temp = *head;

	while (temp)
	{
		h = temp;
		temp1 = temp->next;

		temp2 = temp->next;
		temp->next = temp->prev;
		temp->prev = temp2;
		temp = temp1;
	}
	*head = h;
	return (prev_head);
}
