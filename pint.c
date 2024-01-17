#include "monty.h"

/**
 * f_pint - Print the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @number: Line number.
 * Return: no return
 */
void f_pint(stack_t **stack, unsigned int number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
