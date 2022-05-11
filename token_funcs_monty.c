#include <string.h>
#include "monty.h"

/**
 * get_func - Matches an opcode with a function if one exists
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the function or NULL
 */
void (*get_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"nop", monty_nop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{NULL, NULL}
	};
	int i;

	if (opcode[0] == '#')/*if the line is a comment*/
		return (op_funcs[4].f);
	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

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
	int lineCount = 0, exitStatus = EXIT_SUCCESS;
	stack_t *head = NULL;
	void (*perform_func)(stack_t**, unsigned int);

	if (start_stack(&head) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getdelim(&line, &len, '\n',  monty_fd) != -1)
	{
		if (line[0] == '\n')
		{
			lineCount++;
			continue;
		}
		find_tokens(line);
		lineCount++;
		perform_func = get_func(tokens[0]);
		if (perform_func == NULL)
		{
			exitStatus = unknown_op_error(tokens[0], lineCount);
			free_tokens();
			free_stack(&head);
			break;
		}
		perform_func(&head, lineCount);
		if (!tokens)
		{
			exitStatus = EXIT_FAILURE;
			free_stack(&head);
			break;
		}
		free_tokens();
	}
	free_stack(&head);
	free(line);
	line = NULL;
	len = 0;

	return (exitStatus);
}

/**
 * free_tokens - frees the global tokens variable
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
