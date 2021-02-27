#include <stdio.h>
#include <stdlib.h>
// Calculating the day in 2017
// 2017/01/01 sunday
int main()
{
	int i, month, day, total=0;
	scanf("%d %d", &month, &day);
	for (i = 1; i <= month; i++)
	{
		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			total += 31;
			break;
		case 4: case 6: case 9: case 11:
			total += 31;
			break;
		case 2:
			total += 28;
			break;
		default:
			printf("Wrong date\n");
			return;
		}
	}
	total += day;
	total = total % 7;
	if (total == 0)
		printf("Sunday");
	else if (total == 1)
		printf("Monday");
	else if (total == 2)
		printf("Tuesday");
	else if (total == 3)
		printf("Wednesday");
	else if (total == 4)
		printf("Thrusday");
	else if (total == 5)
		printf("Friday");
	else
		printf("Saturday");
}