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
	fprintf(stderr, "Error: Can't open file %s", file);
	return (EXIT_FAILURE);
}
