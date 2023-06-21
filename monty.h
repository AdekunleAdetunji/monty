#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct app_object - struct containing all necessary app variables
 * @mode: mode of the program: stacks 1 (default), queue (2)
 * @top: top node of stack
 * @bottom: bottom node of stack
 * @l_num: present instruction line
 * @line: present working string from getline
 * @args: parsed arguement:
 * @file: file stram;
 * Description: The only variable will be created as global, and will be
 * referenced in all source codes for easy memory monitoring, and freeing.
*/
typedef struct app_object
{
	int mode;
	stack_t *top;
	stack_t *bottom;
	int l_num;
	char *line;
	char **args;
	FILE *file;
} app_core;
extern app_core app;

/*app utils*/
int len(char **argv);
void free_app(void);
int count(char *lineptr, char *delim);
char **vectorize(char *lineptr, char *delim);

/*list manipulations*/
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *delete_dnode_at_head(stack_t **head);
stack_t *delete_dnode_at_bottom(stack_t **bottom);
size_t print_dlistint(const stack_t *h);
void free_dlistint(stack_t *head);

/*Instructions handling*/
void (*select_inst(char *code))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/*error printing*/
void monty_usage_err(void);
void monty_file_err(char *file_name);
void instructions_err(int l_num, char *inst);
void print_err(char *msg, int l_num);

#endif
