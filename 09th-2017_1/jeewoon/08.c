#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sub[100][100];
int subset_num;

void return_subset(int team[], int size) {
	for (int i = 0; i < size; i++)
		sub[subset_num][i] = team[i];
	subset_num++;
}

void subset(int arr[], int team[], int n, int size, int count) {
	if (count < 0) {
		return_subset(team, size);
	}
	else {
		// Ư�� ���Ұ� ���Ե� ���
		team[size - count] = 1;
		subset(arr, team, n, size, count - 1);
		
		// Ư�� ���Ұ� ���Ե��� ���� ���
		team[size - count] = 0;
		subset(arr, team, n, size, count);
	}
}

void solution() {
	int n;
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	int team_num[2];
	if (n % 2 == 0) { // �л� ���� ¦���� ���
		team_num[0] = n / 2;
		team_num[1] = n / 2;
	}
	else { // �л� ���� Ȧ���� ���
		team_num[0] = (n - 1) / 2;
		team_num[1] = n - team_num[0];
	}

	//int team[2][50];
	subset_num = 0;
	int* team0 = (int*)malloc(sizeof(int) * n); // Ư������ ���� ���� 0,1�� ǥ��
	int* team1 = (int*)malloc(sizeof(int) * n); // Ư������ ���� ���� 0,1�� ǥ��
	subset(arr, team0, n, team_num[0], team_num[0]);

	int idx, min;
	int answer[2] = { 0, 0 };
	for (int i = 0; i < subset_num; i++) {
		for (int j = 0; j < n; j++) {
			if (team0[j] == 0) // team0�� �������� ������ team1�� ����
				team1[j] = 1;
		}

		// team0, team1 ���� ü�� �� ��
		int sum_team0 = 0, sum_team1 = 0;
		for (int j = 0; j < team_num[0]; j++)
			sum_team0 += team0[j];
		for (int j = 0; j < team_num[1]; j++)
			sum_team1 += team1[j];

		// �ּڰ� �ʱ�ȭ
		if (i == 0)
			min = abs(sum_team0 - sum_team1);

		// �ּڰ� ����, �׶��� �κ����� idx ���
		if (min > sum_team0 - sum_team1) {
			min = abs(sum_team0 - sum_team1);
			idx = i;
			answer[0] = sum_team0;
			answer[1] = sum_team1;
		}
	}
	
	// �� �� �� �� ���� �� ���� ���
	if (answer[0] < answer[1]) {
		printf("%d\n", answer[0]);
		printf("%d\n", answer[1]);
	}
	else {
		printf("%d\n", answer[1]);
		printf("%d\n", answer[0]);
	}
}

int main() {
	solution();
}