#ifndef MONTY_H_
#define MONTY_H_
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
 * struct glob_s - global and its funcs
 * @fd: File descriptor
 * @line: Line to getline
 *
 * Description: To handle the file and getline
 */
typedef struct glob_s
{
	FILE *fd;
	char *line;
} glob_t;

/* globals */
extern glob_t global;
extern int value;

/* utilities */

/* create new node */
stack_t *NewNode(int value);

/* check if stack is empty */
int isEmpty(stack_t **stack);

int isvalid_digit(char *arg);

/* get_opcode.c */
int get_opc(stack_t **stack, char *arg, char *item, int count);

/* operations- SET A */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);

/* operations- SET B */
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/* cleaup functions */
void free_stack(stack_t *stack);
void free_lineptr(void *arg);

/* monty.c */
void handle_command(char *argv);

/* error handler */
void push_failure(FILE *fd, char *line, stack_t *stack, int count);
void no_command(FILE *fd, char *line, stack_t *stack, char *count, int item);

#endif /* MONTY_H_ */