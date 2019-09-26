#include "monty.h"
char *mc_token;
/**
 *mop_pop - removes node from top of the stack
 *@head: head of the stack
 *@line_number: number where command is for possible error mesasge
 */
void mop_pop(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	free(*head);
	*head = aux;
}
/**
 *mop_swap - swap top two elements of the stack
 *@head: head of the stack
 *@line_number: number where command is for possible error mesasge
 */
void mop_swap(stack_t **head, unsigned int l_n)
{
	stack_t *aux;
	int count = 0, to_a = 0, to_b = 0;

	aux = *head;
	while(aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	to_b = (*head)->n;
	to_a = aux->n;
	aux->n = to_b;
	(*head)->n = to_a;
}
