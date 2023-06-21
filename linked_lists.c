#include "monty.h"
/**
 * add_dnodeint - add a node to the beginning of a the stack
 * @head: pointer to head node
 * @n: integer to add
 * Return: address of new node or NULL if failed
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *h, *new;

	if (!head)
		return (NULL);
	h = *head;
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	if (h)
		h->prev = new;
	new->next = h;
	*head = new;
	return (new);
}

/**
 * add_dnodeint_end - adds a node to the end of the queue
 * @head: pointer to head node
 * @n: integer to add
 * Return: address of new element or NULL
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *h;

	if (!head)
		return (NULL);
	h = *head;
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = new->prev = NULL;
	if (!h)
	{
		*head = new;
		return (new);
	}
	while (h->next)
		h = h->next;
	h->next = new;
	new->prev = h;
	return (new);
}

/**
 * delete_dnode_at_head - deletes the node at head
 * @head: pointer to head node
 * @index: index to delete
 * Return: 1 if success, -1 if failed
*/
int delete_dnode_at_head(stack_t **head, unsigned int index)
{
	stack_t *prior, *h, *next;
	unsigned int i;

	h = *head;
	next = h->next;
	free(h);
	if (next)
		next->prev = NULL;
	*head = next;
	return (1);
}
/**
 * delete_dnode_at_bottom - deletes the node at bottom
 * @bottom: pointer to head node
 * @index: index to delete
 * Return: 1 if success, -1 if failed
*/
int delete_dnode_at_bottom(stack_t **bottom, unsigned int index)
{
	stack_t *prior, *b, *prev;
	unsigned int i;

	b = *bottom;
	prev = b->prev;
	free(b);
	if (prev)
		prev->next = NULL;
	*bottom = prev;
	return (1);
}
