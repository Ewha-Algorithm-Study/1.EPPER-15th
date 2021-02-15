#include <stdio.h>
#include <stdlib.h>

int solution() {
	int* arr = (int*)malloc(sizeof(int) * 3);
	int k, answer = 0;

	for (int i = 0; i < 3; i++)
		scanf_s("%d", &arr[i]);
	scanf_s("%d", &k);

	// 각 원소가 k인 경우
	for (int i = 0; i < 3; i++) {
		if (arr[i] == k)
			answer++;
	}
	// 두개씩 더했을 때 k인 경우
	if (arr[0] + arr[1] == k)
		answer++;
	if (arr[1] + arr[2] == k)
		answer++;
	if (arr[2] + arr[0] == k)
		answer++;
	// 세개 모두 합이 k인 경우
	if (arr[0] + arr[1] + arr[2] == k)
		answer++;

	return answer;
}

int main() {
	printf("%d", solution());
}