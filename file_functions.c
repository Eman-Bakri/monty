#include "monty.h"

/**
 * f_open - to open a file
 * @fname: path to file
 * Return: void
 */

void f_open(char *fname)
{
	FILE *fdis = fopen(fname, "r");

	if (fname == NULL || fdis == NULL)
		error_msg(2, fname);

	f_read(fdis);
	fclose(fdis);
}


/**
 * f_read - reads a file
 * @fdis: file descriptor pointer
 * Return: void
 */

void f_read(FILE *fdis)
{
	int linenum, arrstyle = 0;
	char *buff = NULL;
	size_t length = 0;

	for (linenum = 1; getline(&buff, &length, fdis) != -1; linenum++)
	{
		arrstyle = line_sprt(buff, linenum, arrstyle);
	}
	free(buff);
}


/**
 * line_sprt - Separates lines into tokens
 * @buff: line from the file
 * @linenum: line number
 * @arrstyle:  arrangment storing format.
 * Return: Returns 0 for stack. 1 for queue.
 */

int line_sprt(char *buff, int linenum, int arrstyle)
{
	char *opcode, *elemval;
	const char *sprt = "\n ";

	if (buff == NULL)
		error_msg(4);

	opcode = strtok(buff, sprt);
	if (opcode == NULL)
		return (arrstyle);
	elemval = strtok(NULL, sprt);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_exec(opcode, elemval, linenum, arrstyle);
	return (arrstyle);
}

/**
 * func_exec - execute the right opcode function
 * @opcode: opcode
 * @argval: opcode argument
 * @arrstyle:  storing format.
 * @linenum: line number
 * Return: void
 */
void func_exec(char *opcode, char *argval, int linenum, int arrstyle)
{
	int a;
	int check;

	instruction_t code_list[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_poptop},
		{"nop", stack_nop},
		{"swap", stack_swap},
		{"add", stack_addtops},
		{"sub", stack_subtops},
		{"div", stack_divtops},
		{"mul", stack_multops},
		{"mod", stack_mod},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{"rotl", stack_rotl},
		{"rotr", stack_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (check = 1, a = 0; code_list[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, code_list[a].opcode) == 0)
		{
			func_exec2(code_list[a].f, opcode, argval, linenum, arrstyle);
			check = 0;
		}
	}
	if (check == 1)
		error_msg(3, linenum, opcode);
}


/**
 * func_exec2 - execute the required function.
 * @reqfunc: Pointer to the required function
 * @opstring: string have opcode.
 * @strval: string contain a numeric value.
 * @linenum: line numeber.
 * @arrstyle: arrangement specifier.
 */
void func_exec2(op_func reqfunc, char *opstring,
		char *strval, int linenum, int arrstyle)
{
	stack_t *mynode;
	int check;
	int a;

	check = 1;
	if (strcmp(opstring, "push") == 0)
	{
		if (strval != NULL && strval[0] == '-')
		{
			strval = strval + 1;
			check = -1;
		}
		if (strval == NULL)
			error_msg(5, linenum);
		for (a = 0; strval[a] != '\0'; a++)
		{
			if (isdigit(strval[a]) == 0)
				error_msg(5, linenum);
		}
		mynode = node_new(atoi(strval) * check);
		if (arrstyle == 0)
			reqfunc(&mynode, linenum);
		if (arrstyle == 1)
			queue_add(&mynode, linenum);
	}
	else
		reqfunc(&head, linenum);
}

