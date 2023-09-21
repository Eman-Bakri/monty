#include "monty.h"

/**
 * error_msg - Prints error messages according to error code.
 * @errcode: Error codes.
 */
void error_msg(int errcode, ...)
{
	va_list ar;
	char *opcode;
	int linenum;

	va_start(ar, errcode);
	switch (errcode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ar, char *));
			break;
		case 3:
			linenum = va_arg(ar, int);
			opcode = va_arg(ar, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", linenum, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ar, int));
			break;
		default:
			break;
	}
	set_free();
	exit(EXIT_FAILURE);
}

/**
 * error_msg2 - prints error messages for math according to error code.
 * @errcode: Error codes.
 */
void error_msg2(int errcode, ...)
{
	va_list ar;
	char *opcode;
	int linenum;

	va_start(ar, errcode);
	switch (errcode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ar, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ar, int));
			break;
		case 8:
			linenum = va_arg(ar, unsigned int);
			opcode = va_arg(ar, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", linenum, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ar, unsigned int));
			break;
		default:
			break;
	}
	set_free();
	exit(EXIT_FAILURE);
}

/**
 * error_strmsg - prints string related errors.
 * @errcode: Error codes.
 */
void error_strmsg(int errcode, ...)
{
	va_list ar;
	int linenum;

	va_start(ar, errcode);
	linenum = va_arg(ar, int);
	switch (errcode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", linenum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", linenum);
			break;
		default:
			break;
	}
	set_free();
	exit(EXIT_FAILURE);
}

