#include "monty.h"

/**
 * mul_opc - multiplies opcode
 * @head: stack head
 * @num: line
 */

void mul_opcode(stack_t **head, unsigned int num)
{
	stack_t *run;
	int count = 0, ax;

	run = *head;
	while (run)
	{
		run = run->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	run = *head;
	ax = run->next->n * run->n;
	run->next->n = ax;
	*head = run->next;
	free(run);
}
