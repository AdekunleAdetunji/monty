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
		monty_usage_err();

	app.file = fopen(argv[1], "r");
	if (!app.file)
		monty_file_err(argv[1]);

	while ((char_count = getline(&(app.line), &n, app.file)) != -1)
	{
		app.args = vectorize(app.line, delim);
		if (app.args)
		{
			if (app.args[0][0] != '#') /*comments handling*/
			{
				f = select_inst(app.args[0]);
				if (!f)
					instructions_err(app.l_num, app.args[0]);
				f(&(app.top), app.l_num);
			}
			free(app.args);
			app.args = NULL;
		}
		app.l_num++;
	}

	free_app();
	exit(EXIT_SUCCESS);
}
