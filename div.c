#include "monty.h"

/**
 * my_div - function that divides the top two elements
 * of the stack by Implementing the div opcode.
 * @t: stack head
 * @count: line_number
 * Return: NULL
*/

void my_div(stack_t **t, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
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

	aux = p->next->n / p->n;
	p->next->n = aux;
	*t = p->next;
	free(p);
}
