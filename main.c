#include "monty.h"
app_core app = {1, NULL, NULL, 1, NULL, NULL, NULL};
/**
 * main - Entry point to interpreter
 * @argv: The vector of command line argument strings
 * @argc: The number of arguments supplied to the command line
 * Return: Exit_success or Exit_failure
 */
int main(int argc, char **argv)
{
	char *delim = " \n\t";
	size_t n;
	ssize_t char_count;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	app.file = fopen(argv[1], "r");
	if (!app.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((char_count = getline(&(app.line), &n, app.file)) != -1)
	{
		app.args = vectorize(app.line, delim);
		if (app.args)
		{
			f = select_inst(app.args[0]);
			if (!f)
			{
				fprintf(stderr,
					"L%d: unknown instruction %s\n",
					app.l_num,
					app.args[0]);
				free_app();
				exit(EXIT_FAILURE);
			}
			f(&(app.top), app.l_num);
			free(app.args);
			app.args = NULL;
		}
		app.l_num++;
	}

	free_app();
	exit(EXIT_SUCCESS);
}
