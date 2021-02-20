#include <stdio.h>
#include <stdlib.h>

int solution() {
	int date, date_last, n, car_last, answer = 0;
	scanf_s("%d", &date);
	scanf_s("%d", &n);

	int* car = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &car[i]);

	date_last = date % 10; // 날짜 1의 자리 계산

	for (int i = 0; i < n; i++) {
		car_last = ((car[i] % 1000) % 100) % 10; // 차번호 1의 자리 계산
		if (car_last == date_last || car_last == (date_last + 5) % 10) // 금지 날짜 or 금지 날짜 + 5와 같으면 위반 차량 대수 증가
			answer++;
	}

	return answer;
}

int main() {
	printf("%d", solution());
}