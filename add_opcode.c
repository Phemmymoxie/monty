#include "monty.h"

/**
 * my_add - function that adds the top two elements
 * of the stack by Implement the add opcode
 * @t: stack head
 * @count: line_number
 * Return: NULL
*/

void my_add(stack_t **t, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}

	p = *t;
	aux = p->n + p->next->n;
	p->next->n = aux;
	*t = p->next;
	free(p);
}
