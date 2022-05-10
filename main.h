#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* GLOBAL VARIABLE - STORE TOKENS FROM INPUT FILE */
extern char **tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
 int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Tokenising functions */
int find_word_count(char *line);
char *get_next_word(char *str);
int curr_word_size(char *line);
void find_tokens(char *line);
void free_tokens();
void print_tokens(); /* used for testing purposes*/
int execute_file(FILE *monty_fd);

/* error functions */
int useage_error(void);
int file_open_error(char *file);

#endif
