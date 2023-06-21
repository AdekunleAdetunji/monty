#include "monty.h"

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
