#include "monty.h"

/**
 * my_pchar - prints the char at the top of the stack,
 * followed by a new line by Implement the pchar opcode
 * @t: stack head
 * @count: line_number
 * Return: NULL
*/

void my_pchar(stack_t **t, unsigned int count)
{
	stack_t *p;

	p = *t;

	if (!p)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}

	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*t);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", p->n);
}
