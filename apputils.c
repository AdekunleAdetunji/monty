#include "monty.h"
/**
 * len - check for the length of an array
 * @argv: The vector under consideration
 * Return: Number of argument
 */
int len(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
	}

	return (i);
}

/**
 * free_app - used to free the app structure
 */
void free_app(void)
{
	if (app.args)
		free(app.args);
	if (app.line)
		free(app.line);
	free_dlistint(app.top);
	fclose(app.file);
}
