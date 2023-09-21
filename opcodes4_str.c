#include "monty.h"

/*TASK 11*/
/**
 * stack_pchar - prints the Ascii value of a char.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_pchar(stack_t **mystack, unsigned int linenum)
{
	int ascii_val;

	if (mystack == NULL || *mystack == NULL)
		error_strmsg(11, linenum);

	ascii_val = (*mystack)->n;
	if (ascii_val > 127 || ascii_val < 0)
		error_strmsg(10, linenum);
	printf("%c\n", ascii_val);
}

/*TASK 12*/
/**
 * stack_pstr - prints a string at the top.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_pstr(stack_t **mystack, __attribute__((unused))unsigned int linenum)
{
	int ascii_val;
	stack_t *ts;

	if (mystack == NULL || *mystack == NULL)
	{
		printf("\n");
		return;
	}

	ts = *mystack;
	while (ts != NULL)
	{
		ascii_val = ts->n;
		if (ascii_val > 127 || ascii_val <= 0)
			break;
		printf("%c", ascii_val);
		ts = ts->next;
	}
	printf("\n");
}
/*TASK 13*/
/**
 * rotl - rotates the stack to the top.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_rotl(stack_t **mystack, __attribute__((unused))unsigned int linenum)
{
	stack_t *ts;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)
		return;

	ts = *mystack;
	while (ts->next != NULL)
		ts = ts->next;

	ts->next = *mystack;
	(*mystack)->prev = ts;
	*mystack = (*mystack)->next;
	(*mystack)->prev->next = NULL;
	(*mystack)->prev = NULL;
}

/*TASK 14*/
/**
 * rotr - rotates the stack to the bottom.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_rotr(stack_t **mystack, __attribute__((unused))unsigned int linenum)
{
	stack_t *ts;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)
		return;

	ts = *mystack;

	while (ts->next != NULL)
		ts = ts->next;

	ts->next = *mystack;
	ts->prev->next = NULL;
	ts->prev = NULL;
	(*mystack)->prev = ts;
	(*mystack) = ts;
}

