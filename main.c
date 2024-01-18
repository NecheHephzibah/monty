#include "monty.h"

cmdline_t cmd_args = {NULL, NULL, NULL, 0};


void read_file(FILE *file, void **stack);
instruction_t *find_opcode(char *cmd, instruction_t *cmd_arr);
void exec_opcode(char *content, stack_t **stack,
		unsigned int line_number, FILE *file);
void free_stack(stack_t **stack);

/**
  * main - main function tat calls the other functions,
  * it addresses the command line.
  * @argv: array of arguments, monty file, where user
  * input is located.
  * @argc: argument count.
  * Return: 0, success.
  */

int main(int argc, char **argv)
{
	FILE *file;
	void *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(file, &stack);

	free_stack(stack);
	fclose(file);

	return (0);
}

/**
  * read_file - reads the input of a file.
  * @file: the file to be read(opcode).
  * @stack: pointer to the head of the list/node.
  * Return: void.
  */


void read_file(FILE *file, void **stack)
{
	char *contents = NULL;
	unsigned int count = 0;
	size_t size = 0;
	ssize_t read_line;

	for (count = 1, (read_line =
				getline(&contents, &size, file)) > 0; count++)
	{
		exec_opcode(contents, stack, count, file);
		free(contents);
	}
}



/**
  * find_opcode - function that searches for the opcode(push,
  * pall, pint, etc) that a user inputs.
  * @cmd: pointer to the command inputed.
  * @cmd_arr: pointer to the array of commands/operations to be
  * carried out.
  * Return: returns NULL.
  */


instruction_t *find_opcode(char *cmd, instruction_t *cmd_arr)
{
	int i = 0;

	while (cmd_arr[i]->opcode != NULL)
	{
		if (strcmp(cmd, cmd_arr[i]->opcode) == 0)
		{
			return (&cmd_arr[i]);
		}
		i++;
	}
	return (NULL);
}

/**
  * exec_opcode - function to execute opcode to be called
  * push, pint, pall, etc on a stack.
  * @contents: pointer to the input from the command line.
  * @stack: pointer to the pointer of the head of a node/list.
  * @line_number: counter stored.
  * @file: pointer to the file the user calls.
  * Return: void
  */

void exec_opcode(char *contents, stack_t **stack,
		unsigned int line_number, FILE *file)
{
	instruction_t cmd_arr[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"nop", _nop}, {"swap", swap_top_two}, {NULL, NULL}
	};
	
	char *command;
	instruction_t *cmd_function;

	command = strtok(contents, " \n\t\r");

	if (command && command[0] == '#')
		return (0);

	cmd_args->args = strtok(NULL, " \n\t\r");
	cmd_function = find_opcode(command, cmd_arr);
	if (cmd_function != NULL)
	{
		cmd_function->f(stack, line_number);
		return (0);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, command);
		fclose(file);
		free(contents);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}



/**
  * free_stack - function to free all the nodes in a stack.
  * @stack: the pointer to the head node.
  * Return: void.
  */

void free_stack(stack_t **stack)
{
	stack_t *current_node;
	stack_t *next_node;

	if (stack == NULL)
		return;

	current_node = *stack;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*stack = NULL;
}
