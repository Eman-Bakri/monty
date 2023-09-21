#include "monty.h"

/*TASK 7*/
/**
 * stack_divtops - divide the stack top two elements by eo.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_divtops(stack_t **mystack, unsigned int linenum)
{
	int result;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)
		error_msg2(8, linenum, "div");

	if ((*mystack)->n == 0)
		error_msg2(9, linenum);
	(*mystack) = (*mystack)->next;
	result = (*mystack)->n / (*mystack)->prev->n;
	(*mystack)->n = result;
	free((*mystack)->prev);
	(*mystack)->prev = NULL;
}

/*TASK 8*/
/**
 * stack_multops - multiply the stack top two elements by eo.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_multops(stack_t **mystack, unsigned int linenum)
{
	int result;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)
		error_msg2(8, linenum, "mul");

	(*mystack) = (*mystack)->next;
	result = (*mystack)->n * (*mystack)->prev->n;
	(*mystack)->n = result;
	free((*mystack)->prev);
	(*mystack)->prev = NULL;
}

/*TASK 9*/
/**
 * stack_mod - computes the mod of division.
 * @mystack: Pointer to stack top node.
 * @linenum: Opcode line number.
 */
void stack_mod(stack_t **mystack, unsigned int linenum)
{
	int result;

	if (mystack == NULL || *mystack == NULL || (*mystack)->next == NULL)

		error_msg2(8, linenum, "mod");


	if ((*mystack)->n == 0)
		error_msg2(9, linenum);
	(*mystack) = (*mystack)->next;
	result = (*mystack)->n % (*mystack)->prev->n;
	(*mystack)->n = result;
	free((*mystack)->prev);
	(*mystack)->prev = NULL;
}

