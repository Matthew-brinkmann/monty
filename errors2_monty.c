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
/**
 * division_error - shot stack error
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int division_error(int lineNum)
{
	fprintf(stderr, "L%d: division by zero\n", lineNum);
	return (EXIT_FAILURE);
}
/**
 * empty_stack_pchar_error - empty stack error when pchar
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int empty_stack_pchar_error(int lineNum)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
	return (EXIT_FAILURE);
}
/**
 * out_range_pchar_error - out of range error when pchar
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int out_range_pchar_error(int lineNum)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
	return (EXIT_FAILURE);
}
