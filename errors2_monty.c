#include "main.h"

/**
 * empty_stack_error - empty stack error
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int empty_stack_error(int lineNum)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
	return (EXIT_FAILURE);
}
/**
 * short_stack_error - empty stack error
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int short_stack_error(int lineNum)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum);
	return (EXIT_FAILURE);
}
/**
 * add_stack_error - empty stack error
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int add_stack_error(int lineNum)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
	return (EXIT_FAILURE);
}
