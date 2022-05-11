#include "main.h"

/**
 * monty_mod - div the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		short_stack_error(line_number, "mod");
		free_tokens();
		return;
	}

	if ((*stack)->next->n == 0)
	{
		division_error(line_number);
		free_tokens();
		return;
	}

	(*stack)->next->n %= (*stack)->n;
	monty_pop(stack, line_number);
}
