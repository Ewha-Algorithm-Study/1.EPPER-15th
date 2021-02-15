#include <stdio.h>
#include <stdlib.h>

void solution() {
	char* input = (char*)malloc(sizeof(char) * 15);
	scanf_s("%s", input);

	int year;
	char sex;
	if (input[7] == '1') {
		year = 19;
		sex = 'M';
	}
	else if (input[7] == '2') {
		year = 19;
		sex = 'F';
	}
	else if (input[7] == '3') {
		year = 20;
		sex = 'M';
	}
	else {
		year = 20;
		sex = 'F';
	}

	printf("%d%c%c-%c%c-%c%c %c", year, input[0], input[1], input[2], input[3], input[4], input[5], sex);

	free(input);
}

int main() {
	solution();
}