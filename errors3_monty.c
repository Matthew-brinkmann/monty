#include "monty.h"

/**
 * empty_stack_pop_error - empty stack error
 * @lineNum: line number
 * Return: EXIT_FAILURE
 */
int empty_stack_pop_error(int lineNum)
{
        fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
        return (EXIT_FAILURE);
}
