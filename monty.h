#ifndef Holberton_h
#define Holberton_h

#define QUEUE "queue"
#define STACK "stack"
#define TOKDEL "\n \r\t"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main.c */
int main(int argc, char *argv[]);
int check_integer(char *m_code, unsigned int l_n);
void tokenizer(char *m_code, unsigned int line_number, stack_t **head);
void push_stack(stack_t **head, int num);
void push_queue(stack_t **head, int num);
void s_func(char *mc_token, unsigned int l_n, stack_t **head);
void mop_pall(stack_t **head, unsigned int line_number);
void freezer(stack_t **head);


#endif
