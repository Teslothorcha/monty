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
	int div = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2 || !(*head) || !head)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	div = aux->n / ((*head)->n);
	aux->n = div;
	free(*head);
	*head = aux;
	(*head)->prev = NULL;
}
/**
 *mop_mul - multiplies the second elemt in the stack by the top elemnt
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_mul(stack_t **head, unsigned int l_n)
{
	stack_t *aux;
	int count = 0;
	int mul = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	mul = aux->n * ((*head)->n);
	aux->n = mul;
	free(*head);
	*head = aux;
	(*head)->prev = NULL;
}
