#include "monty.h"

/**
 * my_mod - fucntion that computes division
 * @t: head of stack
 * @count: counts the number of stacks
 * Return: Void
*/

void my_mod(stack_t **t, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}

	p = *t;

	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}

	aux = p->next->n % p->n;
	p->next->n = aux;
	*t = p->next;
	free(p);
}
