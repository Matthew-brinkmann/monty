#include "monty.h"
#include <stdio.h>

/**
 * monty_rotl - rotate the stack to the top
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = NULL;
	stack_t *head = NULL;

	(void)line_number;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	tail = (*stack)->next;
	while (tail->next != NULL)
		tail = tail->next;
	head = (*stack)->next;
	(*stack)->next = head->next;
	head->next->prev = *stack;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

/**
 * monty_rotr - rotate the stack to the bottom
 * @stack: a pointer to the top node of the stack
 * @line_number: the current line number of monty file
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = NULL;
	stack_t *head = NULL;

	(void)line_number;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	tail = (*stack)->next;
	while (tail->next != NULL)
		tail = tail->next;
	head = (*stack)->next;
	tail->prev->next = NULL;
	(*stack)->next = tail;
	tail->prev = *stack;
	tail->next = head;
	head->prev = tail;
}
