#include "monty.h"
char *mc_token;
/**
 *main - This is the main function to read monty opcode
 *@argc: number of arguments (File) to read
 *@argv: vector containing the arguments
 *Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *f_;
	size_t sizze;
	stack_t *head = NULL;
	char *m_code = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_ = fopen(argv[1], "r");
	if (!(f_) || f_ == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&m_code, &sizze, f_)) != EOF)
	{
		line_number++;
		tokenizer(m_code, line_number, &head, f_);
	}
	free(m_code);
	freezer(&head);
	fclose(f_);
	exit(EXIT_SUCCESS);
}
/**
 *tokenizer - get tokens from file line
 *@m_code: line of the document to get token from
 *@l_n: number of the line where the token belongs
 *@head: head of the stack
 *@f_: file descriptor to close
 *
 */
void tokenizer(char *m_code, unsigned int l_n, stack_t **head, FILE *f_)
{
	int status = 0;
	int n_num = 0;

	mc_token = strtok(m_code, TOKDEL);
	if (mc_token && strcmp(mc_token, QUEUE) == 0)
	{
		status = 1;
		mc_token = NULL;
	}
	else if (mc_token && strcmp(mc_token, STACK) == 0)
	{
		status = 0;
		mc_token = NULL;
	}
	while (mc_token)
	{
		if (strcmp(mc_token, "push") == 0)
		{
			mc_token = strtok(NULL, TOKDEL);
			if (check_integer(head, l_n, m_code, f_))
			{
				n_num = atoi(mc_token);
				if (status == 0)
					push_stack(head, n_num);
				else if (status == 1)
					push_queue(head, n_num);
			}
			mc_token = NULL;
		}
		else
		{
			s_func(l_n, head);
			mc_token = NULL;
		}
	}
}
/**
 *check_integer - checks if arg for push is an integer
 *@head: head of the stack
 *@l_n: number of the commmand for possible error
 *@m_code: line from file to free if necesary
 *@f_: file descriptor to close
 *Return: 1 if str is number 0 if not
 *
 */
int check_integer(stack_t **head, unsigned int l_n, char *m_code, FILE *f_)
{
	int count = 0;

	if (mc_token && (mc_token[count] == '-' ||  mc_token[count] == '+'))
		count++;
	while (mc_token && mc_token[count] != '\0')
	{
		if (isdigit(mc_token[count]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_n);
			freezer(head);
			free(m_code);
			fclose(f_);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	if (!mc_token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l_n);
		freezer(head);
		free(m_code);
		fclose(f_);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**
 *s_func - searches for function related to the token
 *@l_n: line where command is for possible error message
 *@head: head of the stack
 */
void s_func(unsigned int l_n, stack_t **head)
{
	int count = 0;
	instruction_t m_opcodes[] = {
		{"pall", mop_pall},
		{"pint", mop_pint},
		{NULL, NULL}
	};


	while (m_opcodes[count].opcode != NULL)
	{
		if (strcmp(m_opcodes[count].opcode, mc_token) == 0)
		{
			m_opcodes[count].f(head, l_n);
			return;
		}
		count++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l_n, mc_token);
	exit(EXIT_FAILURE);
}
