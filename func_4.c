#include "monty.h"
char *mc_token;
/**
 *mop_rotl - send top of the stack to the end
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_rotl(stack_t **head, unsigned int l_n)
{
	stack_t *aux = NULL, *aux1 = NULL;

	(void) l_n;
	aux = *head;
	aux1 = (*head)->next;
	if (!(*head) || !(*head)->next)
		return;
	while (aux->next)
		aux = aux->next;
	aux->next = *head;
	(*head)->next = NULL;
	(*head)->prev = aux;
	aux1->prev = NULL;
	*head = aux1;
}
