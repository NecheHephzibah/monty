#include "monty.h"

void _pint(stack_t **stack, unsigned int number);


/**
  * get_top_value - function to get the value at the top
  * of the stack.
  * @stack: pointer to the head of the stack.
  * @number: Line number:
  * Return: top value.
  */

int get_top_value(stack_t **stack, unsigned int number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number);
		free(cmd_args.contents);
		fclose(cmd_args.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
		return ((*stack)->n);
}

/**
 * _pint - Print the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @number: Line number.
 * Return: no return
 */
void _pint(stack_t **stack, unsigned int number)
{
	int top_value;

	top_value = get_top_value(stack, number);

	printf("%d\n", top_value);
}

