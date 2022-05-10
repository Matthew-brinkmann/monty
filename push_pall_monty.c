#include <stdlib.h>
#include "main.h"

/**
 * monty_push - push an element to the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;

	/*if we pass the number 0 to atoi, we ge the same result as an error */
	if (tokens[1] == NULL || atoi(tokens[1]) == 0)
	{
		no_integer_error(line_number);
		free_tokens();
		return;
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		malloc_error();
		return;
	}
	newnode->n = atoi(tokens[1]);
	newnode->prev = NULL;
	newnode->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 * monty_pall - print all the values
 * @stack: a pointer to the top node of the stack
 * @line_number: the currently line number of monty file
 */
void monty_pall(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;
	if (*stack == NULL)
		return;

	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
