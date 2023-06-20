#include "monty.h"

/**
 * main - Entry point to interpreter
 * @argv: The vector of command line argument strings
 * @argc: The number of arguments supplied to the command line
 * Return: Exit_success or Exit_failure
 */
int main(int argc, char **argv)
{
	int i;
	char *lineptr = NULL, *delim = " \n\t", **vector = NULL;
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

	while ((char_count = getline(&lineptr, &n, file)) != -1)
	{
		vector = vectorize(lineptr, delim);
		puts("New run");
		for (i = 0; vector && vector[i]; i++)
			puts(vector[i]);

		if (vector)
			free(vector);
	}

	free(lineptr);
	fclose(file);
	exit(EXIT_SUCCESS);
}
