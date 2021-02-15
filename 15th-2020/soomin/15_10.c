#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 100 students
// If the student gets the answer right, all students in the same row or column -> +1
// If the student gets the answer wrong, all students in the same row or column -> -1
// Student with correct answer: 3
// Student with wrong answer: 1
// Student who didn't answer: 2
int** solution(int (*point)[10], size_t point_rows, size_t point_cols)
{
	// Be careful when passing an array as double pointer
	// A[][] -> int(*point)[10] (int** point (X))
	int** answer = (int**)malloc(sizeof(int*) * point_rows);
	int i, j, n;
	for (i = 0; i < point_rows; i++)
	{
		answer[i] = (int*)malloc(sizeof(int) * point_cols);
		for (j = 0; j < point_cols; j++)
			answer[i][j] = 2;
	}
	// Set the point by subtacting 50 points (default score)
	for (i = 0; i < point_rows; i++)
	{
		for (j = 0; j < point_cols; j++)
		{
			point[i][j] -= 50;
		}
	}
	// Check the scores of all students
	for (i = 0; i < point_rows; i++)
	{
		for (j = 0; j < point_cols; j++)
		{
			// Check the neighboring numbers
			// If all neighboring numbers are same and positive, 3
			// If all neighboring numbers are same and negative, 1
			// flag for checking the existance of neighbors (corners, edges) 
			int neighbors[4] = { 0 };
			int flag[4] = { 0 };
			if (i - 1 >= 0)
			{
				neighbors[0] = point[i - 1][j];
				flag[0] = 1;
			}
			if (i + 1 <= 9)
			{
				neighbors[1] = point[i + 1][j];
				flag[1] = 1;
			}
			if (j - 1 >= 0)
			{
				neighbors[2] = point[i][j - 1];
				flag[2] = 1;
			}
			if (j + 1 <= 9)
			{
				neighbors[3] = point[i][j + 1];
				flag[3] = 1;
			}
			int temp=0;
			for (n = 0; n < 4; n++)
			{
				if (flag[n] != 0)
				{
					temp = neighbors[n];
					break;
				}
			}
			if (temp > 0)
				answer[i][j] = 3; // correct
			else if (temp == 0)
				answer[i][j] = 2; // didn't answer
			else
				answer[i][j] = 1; // wrong
			// Set the answer for those who doesn't have equal neighbors
			for (n = 0; n < 4; n++)
			{
				if (flag[n] != 0)
				{
					if (temp != neighbors[n])
					{
						answer[i][j] = 2;
						break;
					}
				}
			}
		}
	}
	return answer;
}
int main()
{
	int raw[10][10];
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &raw[i][j]);
		}
	}
	int**answer = solution(raw, 10, 10);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}
}

/*
	if (i == 0)
			{
				if (j == 0)
				{

				}
				else if (j = 9)
				{

				}
				else
				{

				}
			}
			else if (i == 9)
			{
				if (j == 0)
				{

				}
				else if (j = 9)
				{

				}
				else
				{

				}
			}
			else
			{
				if (j == 0)
				{

				}
				else if (j == 9)
				{

				}
				else
				{

				}
			}
*/