#include <stdio.h>

void solution() {
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 1월부터 12월
	char days[15] = "토일월화수목금";

	int m, d;
	scanf_s("%d", &m);
	scanf_s("%d", &d);

	// 1월 1일부터 입력한 날짜까지의 총 날짜 수
	int total_date = 0;
	for (int i = 0; i < m - 1; i++)
		total_date += month[i];
	total_date += d;

	int idx = total_date % 7 * 2; // 나머지 계산해서 요일 확인
	printf("%c%c요일", days[idx], days[idx+ 1]); // 한글은 2byte라서 char 2개로 print
	
}

int main() {
	solution();
}