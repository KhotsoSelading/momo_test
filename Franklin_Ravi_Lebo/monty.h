#ifndef Monty_h
#define Monty_h
#define  _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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


/**
 * struct glo_stru - global function
 * @file_d: File descriptor
 * @get_line: Line to getline
 *
 * Description: To handle the file and getline
 */
typedef struct glo_stru
{
	FILE *file_d;
	char *get_line;
} glo_t;

/* globals */
extern glo_t global;
extern int value;

/* create new node */
stack_t *NewElement(int value);

/* check if stack is empty */
int isClear(stack_t **stack);
int num_validator(char *arg);

/* opc_fun.c */
int opc_fun(stack_t **stack, char *arg, char *item, int cnt);

/* operations- SET A */
void mont_push(stack_t **stack, unsigned int line_number);
void mont_pall(stack_t **stack, unsigned int line_number);
void mont_pint(stack_t **stack, unsigned int line_number);
void mont_pop(stack_t **stack, unsigned int line_number);

/* operations- SET B */
void mont_swap(stack_t **stack, unsigned int line_number);
void mont_add(stack_t **stack, unsigned int line_number);
void mont_nop(stack_t **stack, unsigned int line_number);

/* operations- SET C */
void mont_sub(stack_t **stack, unsigned int line_number);
void mont_div(stack_t **stack, unsigned int line_number);
void mont_mul(stack_t **stack, unsigned int line_number);
void mont_mod(stack_t **stack, unsigned int line_number);

/* cleaup functions */
void empty_stack(stack_t *stack);

/* monty.c */
void command_handler(char *argv);

/* error handler */
void push_err(FILE *file_d, char *get_line, stack_t *stack, int cnt);
void no_cmd(FILE *file_d, char *get_line, stack_t *stack, char *cnt, int item);
void close_and_free(glo_t *global, stack_t *stack);
void res_chck(char *itm, int cnt, glo_t *gb, char *ars, stack_t **stk, int);
void file_err(char *argv);

#endif /* Monty_h */
