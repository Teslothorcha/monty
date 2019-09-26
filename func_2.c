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
