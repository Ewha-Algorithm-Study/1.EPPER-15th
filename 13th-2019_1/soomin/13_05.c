#include <stdio.h>
// Korean identification number abcdef-ghijklm (abcdef: birth date, g: gender)
// print birth date and gender
int main()
{
	int first, second;
	int year, month, day;
	scanf("%d-%d", &first, &second);
	if (second / 1000000 == 1)
	{
		year = 1900 + first / 10000;
		month = (first / 100) % 100;
		day = first % 100;
		printf("%d-%02d-%02d M", year, month, day);
	}
	else if (second / 1000000 == 2)
	{
		year = 1900 + first / 10000;
		month = (first / 100) % 100;
		day = first % 100;
		printf("%d-%02d-%02d F", year, month, day);
	}
	else if (second / 1000000 == 3)
	{
		year = 2000 + first / 10000;
		month = (first / 100) % 100;
		day = first % 100;
		printf("%d-%02d-%02d M", year, month, day);
	}
	else
	{
		year = 2000 + first / 10000;
		month = (first / 100) % 100;
		day = first % 100;
		printf("%d-%2d-%2d F", year, month, day);
	}
}