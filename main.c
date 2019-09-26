#include "monty.h"
/**
 *main - This is the main function to read monty opcode
 *@argc: number of arguments (File) to read
 *@argv: vector containing the arguments
 *Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file_;
	size_t sizze;
	stack_t *head = NULL;
	char *m_code = NULL;
	unsigned int line_number = 0;

	file_ = fopen(argv[1], "r");
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!(file_) || file_ == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&m_code, &sizze, file_)) != EOF)
	{
		line_number++;
		tokenizer(m_code, line_number, &head);
	}
	free(m_code);
	freezer(&head);
	fclose(file_);
	return (0);
}
/**
 *tokenizer - get tokens from file line
 *@m_code: line of the document to get token from
 *@line_number: number of the line where the token belongs
 *@head: head of the stack
 *
 */
void tokenizer(char *m_code, unsigned int line_number, stack_t **head)
{
	char *mc_token = NULL;
	int status = 0;
	int n_num = 0;

	mc_token = strtok(m_code, TOKDEL);
	if (mc_token && strcmp(mc_token, QUEUE) == 0)
	{
		status = 1;
		mc_token = strtok(NULL, TOKDEL);
	}
	else if (mc_token && strcmp(mc_token, STACK) == 0)
	{
		status = 0;
		mc_token = strtok(NULL, TOKDEL);
	}
	while (mc_token)
	{
		if (strcmp(mc_token, "push") == 0)
		{
			mc_token = strtok(NULL, TOKDEL);
			if (check_integer(mc_token, line_number))
			{
				n_num = atoi(mc_token);
				if (status == 0)
					push_stack(head, n_num);
				else if (status == 1)
					push_queue(head, n_num);
			}
			mc_token = strtok(NULL, TOKDEL);
		}
		else
			s_func(mc_token, line_number, head);
			mc_token = strtok(NULL, TOKDEL);
	}
}
/**
 *check_integer - checks if arg for push is an integer
 *@m_code: string token to be verfifed
 *@l_n: number of the commmand for possible error
 *Return: 1 if str is number 0 if not
 *
 */
int check_integer(char *m_code, unsigned int l_n)
{
	int count = 0;

	if (m_code && m_code[count] == '-')
		count++;
	while (m_code && m_code[count] != '\0')
	{
		if (isdigit(m_code[count]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_n);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	if(!m_code)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l_n);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**
 *s_func - searches for function related to the token
 *@mc_token: function command tokenized
 *@l_n: line where command is for possible error message
 *@head: head of the stack
 */
void s_func(char *mc_token, unsigned int l_n, stack_t **head)
{
	int count = 0;
	instruction_t m_opcodes[] = { {"pall", mop_pall}, {NULL, NULL} };


	while (m_opcodes[count].opcode != NULL)
	{
		if (strcmp(m_opcodes[count].opcode, mc_token) == 0)
		{
			m_opcodes[count].f(head, l_n);
			return;
		}
		count++;
	}
	printf("L%d: unknown instruction %s\n", l_n, mc_token);
	exit(EXIT_FAILURE);
}
