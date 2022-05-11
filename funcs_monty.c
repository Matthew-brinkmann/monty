#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * monty_push - push an element to the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	int i = 0, addSuccess;

	if (tokens[1] == NULL || (tokens[1][0] == '-' && !tokens[1][1]))
	{
		no_integer_error(line_number);
		free_tokens();
		return;
	}
	for (; tokens[1][i]; i++)
	{
		if (tokens[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (isdigit(tokens[1][i]) == 0)
		{
			no_integer_error(line_number);
			free_tokens();
			return;
		}
	}
	if (stack_mode(*stack) == 0)
	{
		addSuccess = add_to_stack(stack, atoi(tokens[1]));
		if (addSuccess == 0)
		{
			malloc_error();
			return;
		}
	}
	else if (stack_mode(*stack) == 1)
	{
		addSuccess = add_to_queue(stack, atoi(tokens[1]));
		if (addSuccess == 0)
		{
			malloc_error();
			return;
		}
	}
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
	tmp = (*stack)->next;
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

	head = (*stack)->next;
	if ((*stack)->next == NULL)
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

	if ((*stack)->next == NULL)
	{
		empty_stack_pop_error(line_number);
		free_tokens();
		return;
	}
	if (!((*stack)->next->next))
	{
		free((*stack)->next);
		(*stack)->next = NULL;
		return;
	}
	tmp = (*stack)->next->next;
	tmp->prev = *stack;
	tmp->next = (*stack)->next->next->next;
	free((*stack)->next);
	(*stack)->next = tmp;
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
