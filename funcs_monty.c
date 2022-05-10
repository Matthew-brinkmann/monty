#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * monty_push - push an element to the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int i = 0;

	if (tokens[1] == NULL || (tokens[1][0] == '-' && !tokens[1][1]))
	{
		no_integer_error(line_number);
		free_tokens();
		return;
	}
	while (tokens[1][i])
	{
		if (isdigit(tokens[1][i]) == 0)
		{
			no_integer_error(line_number);
			free_tokens();
			return;
		}
		i++;
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		malloc_error();
		free_tokens();
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
void monty_pall(stack_t **stack, unsigned int line_number)
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
	(void)line_number;
}

/**
 * monty_pint - prints the value at the top of the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the currently line number of monty file
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;

	head = *stack;
	if (*stack == NULL)
	{
		empty_stack_error(line_number);
		free_tokens();
		return;
	}
	printf("%d\n", head->n);
}

/**
 * monty_pop - removes the top elements of the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the currently line number of monty file
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (*stack == NULL)
	{
		empty_stack_error(line_number);
		free_tokens();
		return;
	}
	if (!((*stack)->next))
	{
		*stack = NULL;
		return;
	}
	tmp = (*stack)->next;
	tmp->prev = NULL;
	tmp->next = (*stack)->next->next;
	free(*stack);
	*stack = tmp;
}

/**
 * monty_nop - do nothing
 * @stack: a pointer to the top node of the stack
 * @line_number: the currently line number of monty file
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
