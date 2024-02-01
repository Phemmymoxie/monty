#include "monty.h"

/**
 *push_opc - function to add node to stack
 *@head: head of the stack
 *@num: line number
 */
void push_opcode(stack_t **head, unsigned int num)
{
	int n;
	int b = 0;
	int f = 0;

	if (opc.aurg)
	{
		if (opc.aurg[0] == '-')
			b++;
		for (; opc.aurg[b] != '\0'; b++)
		{
			if (opc.aurg[b] > 57 || opc.aurg[b] < 48)
				f = 1; }
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(opc.fl);
			free(opc.content);
			f_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(opc.fl);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi((opc.aurg));
	if ((opc.lf == 0))
		add_nd(head, n);
	else
		add_queue(head, n);
}
/**
 * pall_opc - prints the stack
 * @head: stack head
 * @num: line
 */

void pall_opcode(stack_t **head, unsigned int num)
{
	stack_t *run;
	(void)num;

	run = *head;
	if (run == NULL)
		return;
	while (run)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}
/**
 * nop_opc - nop opcode
 * @head: stack head
 * @num: line_number
 */

void nop_opcode(stack_t **head, unsigned int num)
{
	(void) num;
	(void) head;
}
/**
 * sub_opc - sub opcode
 * @head: stack head
 * @num: line
 */

void sub_opcode(stack_t **head, unsigned int num)
{
	stack_t *run;
	int sub, nodes;

	run = *head;
	for (nodes = 0; run != NULL; nodes++)
		run = run->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(opc.fl);
		free(opc.content);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	run = *head;
	sub = run->next->n - run->n;
	run->next->n = sub;
	*head = run->next;
	free(run);
}
