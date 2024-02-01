#include "monty.h"

/**
 * my_pop - function that removes the top element of the stack.
 * @t: beginning of stack
 * @count: counts the number of stacks
 * Return: NULL
*/

void my_pop(stack_t **t, unsigned int count)
{
	stack_t *p;

	if (*t == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}
	p = *t;
	*t = p->next;
	free(p);
}
