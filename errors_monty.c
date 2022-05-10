#include "main.h"

/**
 * useage_error - prints error
 *
 * Return: EXIT_FAILURE
 */
int useage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - prints error
 *
 * @file: the file that couldn't be opened
 *
 * Return: EXIT_FAILURE
 */
int file_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}
/**
 * unknown_op_error - prints error
 *
 * @op: the OP that is unknown
 * @line_num: the line number it appeared on.
 *
 * Return: EXIT_FAILURE
 */
int unknown_op_error(char *op, int lineNum)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, op);
	return (EXIT_FAILURE);
}

/**
 * no_integer_error - no integer error
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int no_integer_error(int lineNum)
{
	fprintf(stderr, "L%d: usage: push integer\n", lineNum);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - malloc error
 * Return: EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

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
