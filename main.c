#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
opc_t opc = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t r_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	opc.fl = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r_line > 0)
	{
		content = NULL;
		r_line = getline(&content, &size, file);
		opc.content = content;
		counter++;
		if (r_line > 0)
		{
			exec(content, &stack, counter, file);
		}
		free(content);
	}
	f_stack(stack);
	fclose(file);
return (0);
}
