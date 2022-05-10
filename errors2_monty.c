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
 * short_stack_error - shot stack error
 * @lineNum: line number
 * @operation: the operation that can't be performed
 * Return: EXIT_FAILURE
 */
int short_stack_error(int lineNum, char *operation)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", lineNum, operation);
	return (EXIT_FAILURE);
}
