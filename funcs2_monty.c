#include "main.h"

/**
 * monty_swap - push an element to the stack
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *hold = NULL;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		short_stack_error(line_number, "swap");
		free_tokens();
		return;
	}

	hold = (*stack)->next->next;
	(*stack)->next->next = hold->next;
	if (hold->next)
		hold->next->prev = (*stack)->next;
	hold->next = (*stack)->next;
	hold->prev = *stack;
	(*stack)->next = hold;
}

/**
 * monty_add - adds the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		short_stack_error(line_number, "add");
		free_tokens();
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - subs the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		short_stack_error(line_number, "sub");
		free_tokens();
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplys the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		short_stack_error(line_number, "mul");
		free_tokens();
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - div the top element from the second top element
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		short_stack_error(line_number, "div");
		free_tokens();
		return;
	}

	if ((*stack)->next->next->n == 0)
	{
		division_error(line_number);
		free_tokens();
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}
