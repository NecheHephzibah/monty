#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


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


/**
  * struct commandLine_s - Represents info from the command line.
  * @args: array of command line arguments.
  * @contents: contents related to the process.
  * @num_conv: number of command line arguments.
  * @file: file associated with the process (monty file).
  *
  * Description: Global variable for ease of access, representing the
  * the command line input in stack or queue format.
  */

typedef struct commandLine_s
{
	char *args;
	int num_conv;
	char *contents;
	FILE *file;
} cmdline_t;

extern cmdline_t cmd_args;

void _push(stack_t **head, unsigned int line_number);
void _addStack(stack_t **head, int num);
void _addQueue(stack_t **head, int num);

void _pall(stack_t **head, unsigned int line_number);

void _pint(stack_t **stack, unsigned int number);
int get_top_value(stack_t **stack, unsigned int number);
void swap_top_two(stack_t **head, unsigned int line_number);


void read_file(FILE *file, stack_t **stack);
instruction_t *find_opcode(char *cmd, instruction_t *cmd_arr);
int exec_opcode(char *content, stack_t **stack,
		unsigned int line_number, FILE *file);
void free_stack(stack_t *stack);

void _nop(stack_t **stack, unsigned int line_number);
#endif

