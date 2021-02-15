#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	char s[14];
	int year[4];
	int month[2];
	int date[2];
	char gender;
	scanf("%s", s);
	int arr[7] = { 0 };
	printf("%c",s[0]);
	for (int i = 0;i < 7;i++) {
		if (i == 6) {
			arr[i] = (int)s[i + 1];
		}
		arr[i] = (int)s[i];
	}
	for (int i = 0;i < 7;i++)
		printf("%d", arr[i]);
	month[0] = arr[2]; month[1] = arr[3];
	date[0] = arr[4]; date[1] = arr[5];
	if (arr[7] == 1) {
		year[0] = 1; year[1] = 9;
		year[2] = arr[0];
		year[3] = arr[1];
		gender = 'M';
	}
	else if (arr[7] == 3) {
		year[0] = 2; year[1] = 0;
		year[2] = arr[0];
		year[3] = arr[1];
		gender = 'M';
	}
	else if (arr[7] == 2) {
		year[0] = 1; year[1] = 9;
		year[2] = arr[0];
		year[3] = arr[1];
		gender = 'F';
	}
	else if (arr[7] == 4) {
		year[0] = 2; year[1] = 0;
		year[2] = arr[0];
		year[3] = arr[1];
		gender = 'F';
	}
	for (int i = 0;i < 4;i++)
		printf("%d", year[i]);
	printf("-%d%d-%d%d %c",month[0],month[1],date[0],date[1],gender);

}