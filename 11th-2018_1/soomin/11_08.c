#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Encoding a message with the given key
// if length of the message is not a multiple of seven, add letters in alphabetical order
// change the message into a code by following the order in the key
int main()
{
	char string[106];
	char key[8];
	char add[8] = "abcdefg";
	char code[106];
	int i;
	scanf("%s", &string);
	scanf("%s", &key);
	// add letters if message is not a multiple of seven
	int remainder;
	remainder = 7 - strlen(string) % 7;
	if(strlen(string) %7 != 0)
		strncat(string, add, remainder);
	// encode the message into a code
	int cycle = 0;
	for (i = 0; i < strlen(string); i ++)
	{
		if (i != 0 && i % 7 == 0)
			cycle++;
		code[i] = string[cycle * 7 + (int)(key[i % 7] - '0') - 1];
	}
	code[strlen(string)] = '\0';
	printf("%s", code);
}