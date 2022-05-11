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
/**
 * monty_pchar - print char at the top of the stack
 * @stack: a pointer to the top node of the stac
 * @line_number: the current line number of monty file
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		empty_stack_pchar_error(line_number);
		free_tokens();
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		out_range_pchar_error(line_number);
		free_tokens();
		return;
	}
	printf("%c\n", (*stack)->n);
}
/**
 * monty_pstr - print the string starting at the top of the stack
 * @stack: a pointer to the top node of the stac
 * @line_number: the current line number of monty file
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)line_number;
	tmp = *stack;
	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
