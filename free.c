#include "monty.h"

/**
 * f_stack - frees a linked list
 * @head: head of the stack
 * Return: Void
 */

void f_stack(stack_t *head)
{
	stack_t *run;

	run = head;
	while (head)
	{
		run = head->next;
		free(head);
		head = run;
	}
}
