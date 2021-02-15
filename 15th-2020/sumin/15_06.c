#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Postfix Notation without stack
int solution(int m, const char* input)
{
	int answer = 0;
	int op1, op2;
	char cal;
	int i;
	// Calculate the operands (character -> integer)
	op1 = input[0] - '0';
	op2 = input[2] - '0';
	cal = input[4];
	int index = 6; // index in the string
	// First operation
	switch (cal)
	{
	case '+':
		op1 = op1 + op2;
		break;
	case '-':
		op1 = op1 - op2;
		break;
	case '*':
		op1 = op1 * op2;
		break;
	case '/':
		op1 = op1 / op2;
		break;
	}
	// Operate the next operations
	for (i = 0; i < m-3; i ++)
	{
		op2 =  input[index] -'0';
		cal = input[index + 2];
		index += 4;
		switch (cal)
		{
		case '+':
			op1 = op1 + op2;
			break;
		case '-':
			op1 = op1 - op2;
			break;
		case '*':
			op1 = op1 * op2;
			break;
		case '/':
			op1 = op1 / op2;
			break;
		}
	}
	// return the answer
	answer = op1;
	return answer;
}
int main()
{
	int m;
	scanf("%d\n", &m); // m enter
	char* input = (char*)malloc(sizeof(char) * (2*m));
	gets(input); // get the input in string
	printf("%d ", solution( m, input));
}