#include "monty.h"
app_core app = {1, NULL, NULL, 0, NULL, NULL};
/**
 * main - Entry point to interpreter
 * @argv: The vector of command line argument strings
 * @argc: The number of arguments supplied to the command line
 * Return: Exit_success or Exit_failure
 */
int main(int argc, char **argv)
{
	int i;
	char *delim = " \n\t";
	size_t n;
	ssize_t char_count;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((char_count = getline(&(app.line), &n, file)) != -1)
	{
		app.args = vectorize(app.line, delim);
		puts("New run");
		for (i = 0; app.args && app.args[i]; i++)
			puts(app.args[i]);

		if (app.args)
		{
			free(app.args);
			app.args = NULL;
		}
	}

	free(app.line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
