#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// seven numbers out of the given nine numbers adds up to 100
// find the seven numbers
int* solution(int numbers[])
{
	int* answer = (int*)malloc(sizeof(int)*7); 
	int i, j, sum = 0, flag = 0;
	// Add up all the given numbers and subtract 100
	for (i = 0; i < 9; i++)
		sum += numbers[i];
	sum -= 100;
	// Find the index of numbers that adds up to sum
	int index1, index2;
	// From higher number to lower number
	for (i = 8; i >= 0; i--)
	{
		int temp = 0;
		// Skip when number is over sum
		if (numbers[i] > sum) 
			continue;
		else
		{
			// find the index1, subtract from sum
			index1 = i;
			temp = numbers[i];
			temp = sum - temp;
			// check if temp is in the number list
			for (j = i; j >= 0; j--)
			{
				if (numbers[j] == temp)
				{
					flag = 1;
					index2 = j;
					break;
				}
			}
			if ( flag == 1 )
				break;
		}
	}
	// add the seven numbers to the answer list
	j = 0;
	for (i = 0; i < 9; i++)
	{
		if (i != index1 && i != index2)
		{
			answer[j++] = numbers[i];
		}
	}
	return answer;
}
// scan, print the numbers
int main()
{
	int numbers[9]; int i;
	for (i = 0; i < 9; i++)
		scanf("%d", &numbers[i]);
	int* answer = solution(numbers);
	for (i = 0; i < 7; i++)
		printf("%d ", answer[i]);
}