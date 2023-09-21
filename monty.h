#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*basic stack operations*/
stack_t *node_new(int num);
void set_free(void);
void stack_pall(stack_t **mystack, unsigned int linenum);
void stack_push(stack_t **newNod, __attribute__((unused))unsigned int linenum);
void queue_add(stack_t **newNod, __attribute__((unused))unsigned int linenum);

/*file related functions*/
void f_open(char *fname);
int line_sprt(char *buff, int linenum, int arrstyle);
void f_read(FILE *fdis);

/*call and exec req functions*/
void func_exec(char *opcode, char *argval, int linenum, int arrstyle);
void func_exec2(op_func reqfunc, char *opstring, char *strval, int linenum, int arrstyle);

/*nodes operations*/
void stack_pint(stack_t **mystack, unsigned int linenum);
void stack_poptop(stack_t **mystack, unsigned int linenum);
void stack_nop(stack_t **mystack, unsigned int linenum);
void stack_swap(stack_t **mystack, unsigned int linenum);

/*Math nodes functions*/
void stack_addtops(stack_t **mystack, unsigned int linenum);
void stack_subtops(stack_t **mystack, unsigned int linenum);
void stack_divtops(stack_t **mystack, unsigned int linenum);
void stack_multops(stack_t **mystack, unsigned int linenum);
void stack_mod(stack_t **mystack, unsigned int linenum);

/*String operations*/
void stack_pchar(stack_t **mystack, unsigned int linenum);
void stack_pstr(stack_t **mystack, __attribute__((unused))unsigned int linenum);
void stack_rotl(stack_t **mystack, __attribute__((unused))unsigned int linenum);
void stack_rotr(stack_t **mystack, __attribute__((unused))unsigned int linenum);

/*Error handling functins*/
void error_msg(int errcode, ...);
void error_msg2(int errcode, ...);
void error_strmsg(int errcode, ...);

#endif
