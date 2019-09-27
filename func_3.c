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
/**
 *mop_mod - multiplies the second elemt in the stack by the top elemnt
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_mod(stack_t **head, unsigned int l_n)
{
	stack_t *aux;
	int count = 0;
	int mod = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	mod = aux->n % ((*head)->n);
	aux->n = mod;
	free(*head);
	*head = aux;
	(*head)->prev = NULL;
}
/**
 *mop_pchar - prints integer ascii value
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_pchar(stack_t **head, unsigned int l_n)
{
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_n);
		exit(EXIT_FAILURE);
	}
	if (!(*head) || !(head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 *mop_pstr - prints integer of each node of the stack
 *@head: head of the stack
 *@l_n: number where command is for possible error mesasge
 */
void mop_pstr(stack_t **head, unsigned int l_n)
{
	stack_t *aux = NULL;

	(void) l_n;
	aux = *head;
	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
