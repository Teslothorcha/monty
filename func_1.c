#include "monty.h"
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
		printf("Error: malloc failed\n");
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

	aux = *head;
	while (aux)
	{
		if (aux->next != NULL)
			aux = aux->next;
	}
	new->n = num;
	new->prev = aux;
	new->next = NULL;
	if (aux != NULL)
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
