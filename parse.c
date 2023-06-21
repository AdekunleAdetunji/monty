#include "monty.h"
#include <string.h>

/**
 * count - counts the number of words in a string
 * @lineptr: the string to be tokenized
 * @delim: The string delimiter
 * Return: number of words in the string
 */
int count(char *lineptr, char *delim)
{
	int count = 0;
	char *dup, *token;

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
 * @delim: The string delimiter
 * Return: A vecotr of the string token
 */
char **vectorize(char *lineptr, char *delim)
{
	int i = 0, len;
	char *token, **str_vec;

	len = count(lineptr, delim);
	if (len == 0)
		return (NULL);

	str_vec = malloc(sizeof(char *) * (len + 1));
	if (!str_vec)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(lineptr, delim);
	while (token)
	{
		str_vec[i] = token;
		i++;
		token = strtok(NULL, delim);
	}

	str_vec[i] = NULL;
	return (str_vec);
}
