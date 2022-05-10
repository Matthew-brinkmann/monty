#include "main.h"

/**
 * free_stack - Frees a stack
 *
 * @stack: A pointer to the stack to free
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	if (stack == NULL)
		return;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
