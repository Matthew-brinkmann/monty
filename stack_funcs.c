#include "monty.h"

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

/**
 * start_stack - creates the stack at the start
 *
 * @stack: the stack to add on to.
 * Return: SUCCESS if success or FAILURE if failed
 */
int start_stack(stack_t **stack)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (malloc_error());
	}
	new->n = 0;
	new->prev = NULL;
	new->next = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}

/**
 * stack_mode - see's if the stack is to be a stack or queue
 * @stack: the stack to check
 *
 * Return: 0 if stack, 1 if queue, 2 if i made a mistake.
 */
int stack_mode(stack_t *stack)
{
	if (stack->n == 0)
		return (0);
	else if (stack->n == 1)
		return (1);
	return (2);
}

/**
 * add_to_stack - adds element in stack mode
 *
 * @stack: the stack to add too
 * @i: the value for the element
 *
 * Return: 1 if success, 0 if fail
 */
int add_to_stack(stack_t **stack, int i)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		free_tokens();
		return (0);
	}
	newnode->n = i;
	newnode->prev = NULL;
	newnode->next = (*stack)->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = newnode;
	(*stack)->next = newnode;

	return (1);
}

/**
 * add_to_queue - adds element in queue mode
 *
 * @stack: the queue to add too
 * @i: the value for the element
 *
 * Return: 1 if success, 0 if fail
 */
int add_to_queue(stack_t **stack, int i)
{
	stack_t *newnode = NULL, *tmp = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		free_tokens();
		return (0);
	}
	newnode->n = i;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	newnode->prev = tmp;
	newnode->next = NULL;
	tmp->next = newnode;
	return (1);
}
