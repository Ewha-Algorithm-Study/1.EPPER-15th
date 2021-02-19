#include <stdio.h>
#include <stdlib.h>
// Change the digits of the given number and find the minimum number that is larger than the given number
// 1<= p <= 999999
int main()
{
	int answer = 0, p, i = 0, j, k, digits[7], digits_sort[7], digits_new[7];
	// digits: saves the given number
	// digits_sort: saves the digits is ascending order
	// digits_new: saves the answer
	int temp, is_max = 1, check[6] = { 0 };
	scanf("%d", &p);
	// save the numbers in each digit to an array
	temp = p;
	while (temp > 0)
	{
		digits[i] = temp % 10;
		digits_sort[i] = temp % 10;
		temp = temp / 10;
		i++;
	}
	// reverse the sorting order
	for (j = 0; j < i / 2; j++)
	{
		temp = digits[j];
		digits[j] = digits[i - j - 1];
		digits[i - j - 1] = temp;
	}
	// If the number is maximum, return 0
	for (j = 0; j < i - 1; j++)
	{
		if (digits[j] < digits[j + 1])
			is_max = 0;
	}
	if (is_max == 1)
	{
		printf("%d", answer);
		return;
	}
	// sort the numbers using a bubble sort (digits_sort)
	for (j = 0; j < i; j++)
	{
		for (k = 0; k < i - j - 1; k++)
		{
			if (digits_sort[k] > digits_sort[k + 1])
			{
				temp = digits_sort[k + 1];
				digits_sort[k + 1] = digits_sort[k];
				digits_sort[k] = temp;
			}
		}
	}
	int change;
	int current;
	// find the highest digit to change
	for (j = 0; j < i; j++)
	{
		if (digits[j] < digits[j + 1])
			check[j] = 1;
	}

	for (j = i-1; j >=0; j--)
	{
		if (check[j] == 0)
			continue;
		else
		{
			change = j;
			current = digits[j];
			break;
		}
	}
	// mark the numbers used via flag
	int flag[7] = { 0 };
	for (j = 0; j < change; j++)
	{
		for (k = 0; k < i; k++)
		{
			if (digits[j] == digits_sort[k] && flag[k] == 0)
			{
				flag[k] = 1;
				break;
			}
		}
	}
	// save the digits in the answer array
	for (j = 0; j < change; j++)
		digits_new[j] = digits[j];
	// find the maximum number in the left over numbers
	for (j = 0; j < i; j++)
	{
		if (digits_sort[j] > current && flag[j] == 0)
		{
			flag[j] = 1;
			digits_new[change++] = digits_sort[j];
			break;
		}
	}
	// save the left over numbers in ascending order
	for (j = 0; j < i; j++)
	{
		if (flag[j] == 0)
		{
			digits_new[change++] = digits_sort[j];
		}
	}
	// make the new integer using the digits_new
	int digit_ten = 1;
	for (j = i - 1; j >= 0; j--)
	{
		answer += digits_new[j] * digit_ten;
		digit_ten *= 10;
	}
	printf("%d", answer);
}