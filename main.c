#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments list
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_open(argv[1]);
	set_free();
	return (0);
}
