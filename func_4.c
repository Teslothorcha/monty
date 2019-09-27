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

	if (!(*head))
		return;
	if (!(*head)->next)
		return;
	aux = *head;
	aux1 = (*head)->next;
	while (aux->next)
		aux = aux->next;
	aux1->prev = NULL;
	aux->next = *head;
	(*head)->next = NULL;
	(*head)->prev = aux;
	*head = aux1;
}
/**
 *mop_rotr - send top of the stack to the end
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_rotr(stack_t **head, unsigned int l_n)
{
	stack_t *aux = NULL, *aux1 = NULL;

	(void) l_n;
	aux = *head;
	aux1 = *head;
	if (!(*head))
		return;
	if (!(*head)->next)
		return;
	while (aux->next)
		aux = aux->next;
	aux->prev->next = NULL;
	aux->next = aux1;
	aux->prev = NULL;
	aux1->prev = aux;
	*head = aux;
}
