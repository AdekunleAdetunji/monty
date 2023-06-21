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
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
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
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
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
 * Return: 1 if success, -1 if failed
*/
stack_t *delete_dnode_at_head(stack_t **head)
{
	stack_t *h, *next;

	h = *head;
	next = h->next;
	if (next)
		next->prev = NULL;
	*head = next;
	app.top = *head;
	return (h);
}
/**
 * delete_dnode_at_bottom - deletes the node at bottom
 * @bottom: pointer to head node
 * Return: 1 if success, -1 if failed
*/
stack_t *delete_dnode_at_bottom(stack_t **bottom)
{
	stack_t *b, *prev;

	b = *bottom;
	prev = b->prev;
	if (prev)
		prev->next = NULL;
	*bottom = prev;
	app.bottom = *bottom;
	return (b);
}
