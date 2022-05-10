#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * monty_swap - push an element to the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *hold = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		short_stack_error(line_number, "swap");
		free_tokens();
		return;
	}

	hold = (*stack)->next;
	(*stack)->next = hold->next;
	if (hold->next)
		hold->next->prev = *stack;
	hold->next = *stack;
	hold->prev = (*stack)->prev;
	*stack = hold;
}

/**
 * monty_add - adds the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		short_stack_error(line_number, "add");
		free_tokens();
		return;
	}

	(*stack)->next->n += (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - subs the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		short_stack_error(line_number, "sub");
		free_tokens();
		return;
	}

	(*stack)->next->n -= (*stack)->n;
	monty_pop(stack, line_number);
}
