#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// Condensing the string (0, 1)
// Alphabet for number of successive letters(0, 1)
// Add 1 at the front if the string starts with 1 instead of 0
// 1 <= length of src <= 10000, Capital letters 
char* solution(const char* s)
{
	char* answer = (char*)malloc(sizeof(char)*strlen(s));
	int index = 0, i;
	// Add 1 in the front if the string starts with 1
	if (s[0] ==  '1')
		answer[index++] = '1';
	int temp = 0;
	// Count the number of successive letters and compress the string with an alphabet
	for (i=0; i<strlen(s); i++)
	{
		if (s[i] == s[i + 1])
			temp++;
		else
		{
			answer[index++] = (char)('A' + temp );
			temp = 0;
		}
	}
	// add '\0' at the end, as a sign of end
	answer[index] = '\0';
	return answer;
}
// scan the source and print the condensed string
int main()
{
	char* src = (char*)malloc(sizeof(char) * 10001);
	scanf("%s", src);
	printf("%s",solution(src));
}