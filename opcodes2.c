#include "monty.h"

/*TASK 3*/
/**
 * stack_swap - swaps the top two elements of the stack.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_swap(stack_t **mystack, unsigned int linenum)
{
	stack_t *ts;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)
		error_msg2(8, linenum, "swap");
	ts = (*mystack)->next;
	(*mystack)->next = ts->next;
	if (ts->next != NULL)
		ts->next->prev = *mystack;
	ts->next = *mystack;
	(*mystack)->prev = ts;
	ts->prev = NULL;
	*mystack = ts;
}
/*TASK 4*/
/**
 * stack_addtops - adds the stack top two elements.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_addtops(stack_t **mystack, unsigned int linenum)
{
	int result;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)
		error_msg2(8, linenum, "add");

	(*mystack) = (*mystack)->next;
	result = (*mystack)->n + (*mystack)->prev->n;
	(*mystack)->n = result;
	free((*mystack)->prev);
	(*mystack)->prev = NULL;
}

/*TASK 5*/
/**
 * stack_nop - Doesn't do anything.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_nop(stack_t **mystack, unsigned int linenum)
{
	(void)mystack;
	(void)linenum;
}

/*TASK 6*/
/**
 * stack_subtops - subtracts the sack top two elements from eo.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_subtops(stack_t **mystack, unsigned int linenum)
{
	int result;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)

		error_msg2(8, linenum, "sub");


	(*mystack) = (*mystack)->next;
	result = (*mystack)->n - (*mystack)->prev->n;
	(*mystack)->n = result;
	free((*mystack)->prev);
	(*mystack)->prev = NULL;
}

