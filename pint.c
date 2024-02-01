#include "monty.h"

/**
 * my_pint - function that Implement the pint opcode.
 * @t: beginning of stack
 * @count: count number of stacks
 * Return: NULL
 */

void my_pint(stack_t **t, unsigned int count)
{
	if (*t == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*t)->n);
}
