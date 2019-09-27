#include "monty.h"
char *mc_token;
/**
 *push_stack - adds a node to the stack
 *@head: head of the stack
 *@num: number to add to the node
 */
void push_stack(stack_t **head, int num)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
/**
 *push_queue - adds a node to the queue
 *@head: front of the queue
 *@num: number to add to the node
 */
void push_queue(stack_t **head, int num)
{
	stack_t *new = NULL, *aux = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	aux = *head;
	if (!(*head))
	{
		*head = new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}
	while (aux->next)
	{
		aux = aux->next;
	}
	new->prev = aux;
	new->next = NULL;
	aux->next = new;
}
/**
 *mop_pall - prints number of stack nodes
 *@head: head of the stack
 *@line_number: number where command is for possible error mesasge
 */
void mop_pall(stack_t **head, unsigned int line_number)
{
	stack_t *aux = NULL;

	(void) line_number;
	aux = *head;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
	mc_token = NULL;
}
/**
 *freezer - free a stack
 *@head: head of the stack
 */
void freezer(stack_t **head)
{
	stack_t *aux = NULL;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		free(*head);
		*head = aux;
	}
}
/**
 *mop_pint - prints number of stack top
 *@head: head of the stack
 *@line_number: number where command is for possible error mesasge
 */
void mop_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
