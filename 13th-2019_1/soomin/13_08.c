#include <stdio.h>
#include <stdlib.h>
// Postfix Notation with stack
typedef struct stack
{
	char stack[11];
	int top;
}stack;
void initialize(stack *s)
{
	s->top = -1;
}
void push(stack *s, char item)
{
	s->stack[++(s->top)] = item;
}
char pop(stack *s)
{
	return s->stack[(s->top)--];
}
int main()
{
	stack postfix;
	initialize(&postfix);
	int i, m, op1, op2;
	char temp, non, cal;
	scanf("%d\n", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%c", &temp);
		scanf("%c", &non);
		// operands
		if (temp != '+' && temp != '-' && temp != '*' && temp != '/')
			push(&postfix, temp);
		// operators
		else
		{
			cal = temp;
			op2 = (int) pop(&postfix) - '0';
			op1 = (int) pop(&postfix) - '0';
			switch (cal)
			{
			case '+':
				push(&postfix, (char) (op1 + op2) + '0' ); break;
			case '-':
				push(&postfix, (char) (op1 - op2) + '0' ); break;
			case '*':
				push(&postfix, (char) (op1 * op2) + '0' ); break;
			case '/':
				push(&postfix, (char) (op1 / op2) + '0' ); break;
			}
		}
	}
	printf("%d", (int) pop(&postfix)-'0');
}