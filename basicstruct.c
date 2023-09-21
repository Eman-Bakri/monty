#include "monty.h"

/**
 * node_new - makes a new node.
 * @num: Num inside the node.
 * Return: A pointer to node. Otherwise NULL (fails).
 */
stack_t *node_new(int n)
{
	stack_t *newNod;

	newNod = malloc(sizeof(stack_t));
	if (newNod == NULL)
		error_msg(4);
	newNod->next = NULL;
	newNod->prev = NULL;
	newNod->n = n;
	
	return (newNod);
}

/**
 * queue_add - to add a node to the queue.
 * @newNod: Pointer to new node.
 * @linenum: line number.
 */
void queue_add(stack_t **newNod, __attribute__((unused))unsigned int linenum)
{
	stack_t *ts;

	if (newNod == NULL || *newNod == NULL)
		exit(EXIT_FAILURE);
	
	if (head == NULL)
	{
		head = *newNod;
		return;
	}
	ts = head;
	while (ts->next != NULL)
		ts = ts->next;

	ts->next = *newNod;
	(*newNod)->prev = ts;

}

/**
 * set_free - To free nodes in stack.
 */
void set_free(void)
{
	stack_t *ts;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		ts = head;
		head = head->next;
		free(ts);
	}
}
