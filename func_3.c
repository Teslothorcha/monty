#include "monty.h"
char *mc_token;
/**
 *mop_div - divides the second elemt in the stack by the top elemnt
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_div(stack_t **head, unsigned int l_n)
{
	stack_t *aux;
	int count = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too shor\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	aux->n /= ((*head)->n);
	free(*head);
	*head = aux;
}
