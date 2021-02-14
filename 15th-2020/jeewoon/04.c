// 100�����

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int* numbers) {
	int* answer = (int*)malloc(sizeof(int) * 7);

	int sum = 0, i, j, k, flag = 0;

	// ��ü sum ���ϱ�
	for (i = 0; i < 9; i++) {
		sum += numbers[i];
	}

	for (i = 0; i < 8; i++) {
		int total = sum;
		for (j = i + 1; j < 9; j++) {

			// ��ü sum���� ���� �ݺ������� �ϳ��� �����鼭 100�� ��츦 ã��
			if (sum - numbers[i] - numbers[j] == 100) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	
	// ������ ���� �ΰ��� i,j�� ����Ǿ� �����Ƿ� �� ���� ���� �迭 ����
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