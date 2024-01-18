#include "monty.h"

cmdline_t cmd_args;

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
	char *args;
	int num_conv;
	char *contents;
	FILE *file;

	if (argc != 2)
	{
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}





	cmd_args->args = argv;
	cmd_args->num_conv = argc;
	cmd_args->content = NULL;
	cmd_args->file = NULL;
	
}
