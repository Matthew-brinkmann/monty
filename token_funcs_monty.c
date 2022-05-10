#include "main.h"

/**
 * execute_file - executes each line
 *
 * @monty_fd: the file to read line-by-line
 * Return: success status.
 */
int execute_file(FILE *monty_fd)
{
	char *line = NULL;
	size_t len = 0;
	int lineCount = 0;

	while (getdelim(&line, &len, '\n',  monty_fd) != -1)
	{
		if (line[0] == '\n')
		{
			lineCount++;
			continue;
		}
		find_tokens(line);
		lineCount++;
		print_tokens();
		free_tokens();
	}
	free(line);
	line = NULL;
	len = 0;

	return (EXIT_SUCCESS);
}

/**
 * free_tokes - frees the global tokens variable
 *
 * Return: void
 */
void free_tokens(void)
{
	int i = 0;

	if (tokens == NULL)
		return;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	tokens = NULL;
}

/**
 * print_tokens - prints the global token variable
 *
 * Return: void
 */
void print_tokens(void)
{
	int i = 0;

	if (tokens == NULL)
		return;

	for (; tokens[i]; i++)
		printf("token[%d] = %s\n", i, tokens[i]);
}
