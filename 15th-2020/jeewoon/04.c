// 100만들기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int* numbers) {
	int* answer = (int*)malloc(sizeof(int) * 7);

	int sum = 0, i, j, k, flag = 0;

	// 전체 sum 구하기
	for (i = 0; i < 9; i++) {
		sum += numbers[i];
	}

	for (i = 0; i < 8; i++) {
		int total = sum;
		for (j = i + 1; j < 9; j++) {

			// 전체 sum에서 이중 반복문으로 하나씩 빼가면서 100일 경우를 찾기
			if (sum - numbers[i] - numbers[j] == 100) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	
	// 빠지는 숫자 두개가 i,j에 저장되어 있으므로 이 둘을 빼고 배열 당기기
	for (k = 0; k < 9; k++) {
		if (k < i)
			answer[k] = numbers[k];
		else if (k > i && k < j)
			answer[k - 1] = numbers[k];
		else if (k > j)
			answer[k - 2] = numbers[k];
		else
			continue;
	}

	return answer;
}

int main() {
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 79 };
	int* ans = solution(arr);
	for (int i = 0; i < 7; i++) {
		printf("%d ", ans[i]);
	}
}