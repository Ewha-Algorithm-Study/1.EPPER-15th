#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct {
	int stack[100];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

void push(StackType* s, int item) {
	s->stack[++(s->top)] = item;
}

int pop(StackType* s) {
	return s->stack[(s->top)--];
}

int calc(char* exp) {
	int op1, op2, value,i;
	int len = (int)strlen(exp);
	char ch;
	StackType s;
	init(&s);
	for (int i = 0;i < len;i++) {
		ch = exp[i];
		if (ch != '*' && ch != '+' && ch != '/' && ch != '-') {
			value = ch - '0';
			push(&s, value);
			continue;
		}
		op2 = pop(&s);
		op1 = pop(&s);

		switch (ch) {
		case '*':
			value = op1 * op2; break;
		case '+':
			value = op1 + op2; break;
		case '-':
			value = op1 - op2; break;
		case '/':
			value = op1 / op2; break;
		}

		push(&s, value);
	}
	return pop(&s);
}

int main(void) {
	int m = 0;
	scanf("%d", &m);
	int result;
	char postfix[20];
	scanf("%[^\n]", postfix);
	scanf("%s", postfix);
	printf("%d", calc(postfix));
}