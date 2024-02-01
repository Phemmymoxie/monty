#include "monty.h"

/**
 * rotl_opc- rotates the stack to the top
 * @head: stack head
 * @num: line_number
 */

void rotl_opc(stack_t **head,  __attribute__((unused)) unsigned int num)
{
	stack_t *tmp = *head, *run;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	run = (*head)->next;
	run->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = run;
}
/**
 * rotr_opc- rotates the stack to the bottom
 * @head: stack head
 * @num: line_number
 * Return: no return
 */

void rotr_opc(stack_t **head, __attribute__((unused)) unsigned int num)
{
	stack_t *tmp;

	tmp = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}
