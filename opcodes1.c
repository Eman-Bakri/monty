#include "monty.h"

/*TASK 0*/
/**
 * stack_push - pushs a new node to the stack.
 * @newNod: A pointer to the new node.
 * @linenum: Opcode line number.
 */
void stack_push(stack_t **newNod, __attribute__((unused))unsigned int linenum)
{
	stack_t *ts; /*tempeorary space*/

	if (newNod == NULL || *newNod == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNod;
		return;
	}
	ts = head;
	head = *newNod;
	head->next = ts;
	ts->prev = head;
}


/**
 * stack_pall - prints all the values on stack, from the top.
 * @mystack: Pointer to top node.
 * @linenum: Opcode line number.
 */
void stack_pall(stack_t **mystack, unsigned int linenum)
{
	stack_t *ts; /*tempeorary space*/

	(void) linenum;
	if (mystack == NULL)
		exit(EXIT_FAILURE);
	ts = *mystack;

	while (ts != NULL)
	{
		printf("%d\n", ts->n);
		ts = ts->next;
	}
}
/*TASK 1*/
/**
 * stack_pint - prints the stack top node.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_pint(stack_t **mystack, unsigned int linenum)
{
	if (mystack == NULL || *mystack == NULL)
		error_msg2(6, linenum);

	printf("%d\n", (*mystack)->n);
}
/*TASK 2*/
/**
 * stack_poptop - removes the top element of the stack.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_poptop(stack_t **mystack, unsigned int linenum)
{
	stack_t *ts; /*tempeorary space*/

	if (mystack == NULL || *mystack == NULL)
		error_msg2(7, linenum);

	ts = *mystack;
	*mystack = ts->next;
	if (*mystack != NULL)
		(*mystack)->prev = NULL;
	free(ts);
}

