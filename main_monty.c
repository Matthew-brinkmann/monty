#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "monty.h"

char **tokens = NULL;


/**
 * main - main entry into the program
 *
 * @argc: number of inputted variables
 * @argv: list of inputted variables
 *
 * Return: success or failure.
 */
int main(int argc, char **argv)
{
	FILE *monty_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (useage_error());
	monty_fd = fopen(argv[1], "r");
	if (monty_fd == NULL)
		return (file_open_error(argv[1]));
	exit_code = execute_file(monty_fd);
	fclose(monty_fd);
	return (exit_code);
}
