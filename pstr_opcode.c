#include "monty.h"

/**
 * pstr_opc - prints the string
 * @head: stack head
 * @num: line
 */

void pstr_opc(stack_t **head, unsigned int num)
{
	stack_t *run;
	(void)num;

	run = *head;
	while (run)
	{
		if (run->n > 127 || run->n <= 0)
		{
			break;
		}
		printf("%c", run->n);
		run = run->next;
	}
	printf("\n");
}
