#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct opc_s - variables -aurg, fl, ln content
 * @aurg: value
 * @fl: pointer to monty file
 * @content: line content
 * @lf: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct opc_s
{
	char *aurg;
	FILE *fl;
	char *content;
	int lf;
} opc_t;
extern opc_t opc;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_opcode(stack_t **head, unsigned int num);
void sub_opcode(stack_t **head, unsigned int num);
void nop_opcode(stack_t **head, unsigned int num);
void pall_opcode(stack_t **head, unsigned int num);
void mul_opcode(stack_t **head, unsigned int num);
void pstr_opcode(stack_t **head, unsigned int num);
void my_add(stack_t **t, unsigned int count);
void my_div(stack_t **t, unsigned int count);
void my_pint(stack_t **t, unsigned int count);
void my_pop(stack_t **t, unsigned int count);
void my_swap(stack_t **t, unsigned int count);
void my_mod(stack_t **t, unsigned int count);
void my_pchar(stack_t **t, unsigned int count);
void f_stack(stack_t *head);
void my_pstr(stack_t **t, unsigned int count);
void add_queue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int num);
void add_nd(stack_t **head, int n);
void rotl_opc(stack_t **head,  __attribute__((unused)) unsigned int num);
void rotr_opc(stack_t **head, __attribute__((unused)) unsigned int num);
void stack_opc(stack_t **head, unsigned int num);
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file);

#endif
