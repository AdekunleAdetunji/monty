#include "monty.h"

/**
 * count - counts the number of words in a string
 * @lineptr: the string to be tokenized
 * Return: number of words in the string
 */
int count(char *lineptr)
{
	int count = 0;
	char *dup, *delim, *token;

	delim = " ";
	dup = strdup(lineptr);
	if (!dup)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(dup, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}

	free(dup);
	return (count);
}

/**
 * vectorize - tokenize each string and return a vector containing
 * pointer to each token
 * @lineptr: The string to be tokenized
 * @count: The number of words in the string
 * Return: A vecotr of the string token
 */
char **vectorize(char *lineptr, int count)
{
	int i = 0;
	char *dup, *delim, *token, **str_vec;

	str_vec = malloc(sizeof(char *) * count);
	if (!str_vec)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	delim = " ";
	dup = strdup(lineptr);
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(dup, delim);
	while (token)
	{
		str_vec[i] = token;
		i++;
		token = strtok(NULL, delim);
	}

	free(dup);
	return (str_vec);
}


/**
 * main - Entry point to interpreter
 * @argv: The vector of command line argument strings
 * @argc: The number of arguments supplied to the command line
 * Return: Exit_success or Exit_failure
 */
int main(int argc, char **argv)
{
	int wc;
	char *lineptr, *token, *delim, **vector;
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

	(void) delim;
	(void) token;
	(void) vector;
	while ((char_count = getline(&lineptr, &n, file)) != -1)
	{
		wc = count(lineptr);
		printf("Word count: %d\n", wc);
	}

	free(lineptr);
	fclose(file);
	exit(EXIT_SUCCESS);
}
