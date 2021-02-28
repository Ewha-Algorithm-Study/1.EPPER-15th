#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//요일 출력하기
int main() {
	int month;
	int day;
	scanf("%d", &month);
	scanf("%d", &day);
	int count = 0;
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	count = sum(arr, month - 1) + day;
	count = count % 7;
	switch (count) {
	case 1:
		printf("%s", "일요일");
		break;
	case 2:
		printf("%s", "월요일");
		break;
	case 3:
		printf("%s", "화요일");
		break;
	case 4:
		printf("%s", "수요일");
		break;
	case 5:
		printf("%s", "목요일");
		break;
	case 6:
		printf("%s", "금요일");
		break;
	case 0:
		printf("%s", "토요일");
		break;
	}
}

int sum(int arr[],int idx) {
	int sum = 0;
	for (int i = 0;i < idx + 1;i++)
		sum += arr[i];
	return sum;
}