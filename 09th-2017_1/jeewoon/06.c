#include <stdio.h>
#include <math.h>

int solution() {
	int radar[2], r, n, answer = 0;
	double distance;
	int boat[50][2];

	// 입력 받기
	scanf_s("%d", &radar[0]);
	scanf_s("%d", &radar[1]);
	scanf_s("%d", &r);
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &boat[i][0]);
		scanf_s("%d", &boat[i][1]);
	}
	
	// 레이더와의 거리가 3 이하면 감지
	for (int i = 0; i < n; i++) {
		distance = pow((radar[0] - boat[i][0]), 2) + pow((radar[1] - boat[i][1]), 2);
		if (distance <= pow(r, 2))
			answer++;
	}

	return answer;
}

int main() {
	printf("%d", solution());
}