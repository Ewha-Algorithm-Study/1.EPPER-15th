#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Reserving maximum students in the two seat in the library
// Given beginning and finishing time
// 0~86399 seconds
int solution(int s[], size_t s_len, int e[], size_t e_len)
{
	int answer = 0; int i, j;
	// Bubble sort: end time -> start time
	for (i = 0; i < e_len; i++)
	{
		for (j = 0; j < e_len - 1 - i; j++)
		{
			if (e[j] > e[j + 1] || (e[j] == e[j+1] && s[j] > s[j+1]) ) 
				// Don't forget: e[j] == e[j+1] && s[j] > s[j+1]
			{
				int temp;
				temp = e[j + 1];
				e[j + 1] = e[j];
				e[j] = temp;
				temp = s[j + 1];
				s[j + 1] = s[j];
				s[j] = temp;
			}
		}
	}
	// Assign seats 
	int N = s_len, e1 = -1, e2 = -1;
	for (i = 0; i < N; i++)
	{
		int e1_t = 0, e2_t = 0; // end time for seat1 and seat2
		if (i != 0)
		{
			e1_t = e1 - s[i];
			e2_t = e2 - s[i];
		}
		//printf("t: %d %d\n", e1_t, e2_t);
		// Assign seat1
		if (e1 <= s[i] && e1_t >= e2_t)
		{
			e1 = e[i];
			//printf("e1 i = %d\n", i);
			answer++;
		}
		// Assign seat2
		else if (e2 <= s[i])
		{
			e2 = e[i]; 
			//printf("e2 i = %d\n", i);
			answer++;
		}
		// Assign seat1
		else if (e1 <= s[i])
		{
			e1 = e[i];
			//printf("e1 i = %d\n", i);
			answer++;
		}
	}
	return answer;
}
int main()
{
	// Test Cases
	int s[] = { 0,6,3,1,1,2 };
	int e[] = { 3,7,10,5,9,8 };

	//int s[] = { 845, 26921, 15116, 1694, 43588 };
	//int e[] = { 64754, 32669, 57396, 8835, 50160 };

	//int s[] = { 30140, 23679, 17663, 8492, 9777, 17803, 55388, 7420, 23107, 37469 };
	//int e[] = { 55374, 33664, 43614, 12763, 85637, 58156, 79170, 60252, 52676, 48022 };

	//int s[] = { 26656, 30333, 62305, 9449, 3437, 11464, 24600, 44473, 2676 };
	//int e[] = { 27965, 58770, 73192, 80577, 64075, 46143, 57539, 79925, 59944 };

	//int s[] = { 56620, 13173, 45847, 25812, 51664, 292 };
	//int e[] = { 76484, 47717, 52486, 46902, 64451, 56529 };

	//int s[] = { 1,2,3,4,5 };
	//int e[] = { 2,3,4,5,6 };

	size_t s_len = sizeof(s) / 4;
	size_t e_len = sizeof(e) / 4;
	printf("%d", solution(s, s_len, e, e_len));
}
