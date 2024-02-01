#include "monty.h"

/**
 * my_swap - functin that Implement the swap opcode.
 * @t: beginning of stack
 * @count: couts the number of stack
 * Return: NULL
*/

void my_swap(stack_t **t, unsigned int count)
{
	stack_t *p;
	int len = 0, aux;

	p = *t;
	while (p)
	{
		p = p->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}

	p = *t;
	aux = p->n;
	p->n = p->next->n;
	p->next->n = aux;
}
