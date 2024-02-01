#include "monty.h"

/**
 * exec - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */

int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t buff[] = {
				{"push", push_opcode}, {"pall", pall_opcode}, {"pint", my_pint},
				{"pop", my_pop},
				{"swap", my_swap},
				{"add", my_add},
				{"nop", nop_opcode},
				{"sub", sub_opcode},
				{"div", my_div},
				{"mul", mul_opc},
				{"mod", my_mod},
				{"pchar", my_pchar},
				{"pstr", my_pstr},
				{"rotl", rotl_opc},
				{"rotr", rotr_opc},
				{"queue", f_queue},
				{"stack", stack_opc},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	opc.aurg = strtok(NULL, " \n\t");
	while (buff[i].opcode && op)
	{
		if (strcmp(op, buff[i].opcode) == 0)
		{	buff[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && buff[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		f_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
