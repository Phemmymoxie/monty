#include "monty.h"

/**
 * my_pstr - function that prints the string starting at
 * the top of the stack, followed by a new
 * by Implemeningt the pstr opcode
 * @t: beginning of stack
 * @count: number of stacks
 * Return: NULL
*/

void my_pstr(stack_t **t, unsigned int count)
{
	stack_t *p;
	(void)count;

	p = *t;
	while (p)
	{
		if (p->n > 127 || p->n <= 0)
		{
			break;
		}
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}
