#include "main.h"

/**
 * monty_mod - div the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		short_stack_error(line_number, "mod");
		free_tokens();
		return;
	}

	if ((*stack)->next->next->n == 0)
	{
		division_error(line_number);
		free_tokens();
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_stack - changes to a stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = 0;
	(void)line_number;
}

/**
 * monty_queue - changes to a queue
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = 1;
	(void)line_number;
}
