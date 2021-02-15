// e-Queen

// �ڵ� ȿ������ �� �� �ʿ�..

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check[14], d[27], d2[27];
int N, count;
int xy[14][14];

void nqueen(int lev) {
	int i;

	if (lev == N) {	//������ row ����. ����� �� 1�� ã��
		count++;
		return;
	}

	for (i = 0; i < N; i++) {		//�� row�� column�� �ϳ��� Ž��
		if (xy[lev][i]) continue;			//�־��� ���� �� ���� ���� skip
		//�տ� ���� ��ġ�� columnȤ�� �밢���� ���� ��ǥ���� skip
		if (check[i] == 1) continue;			//column
		if (d[i + lev] == 1) continue;			//�������� ���� �밢��
		if (d2[lev - i + 13] == 1) continue;	//�����ʾƷ� ���� �밢��

		//���ο� ��ġ ����. column�� �밢�� ���
		check[i] = 1;
		d[i + lev] = 1;
		d2[lev - i + 13] = 1;

		nqueen(lev + 1);		//������ �۾��� �Ʒ��� row�鿡�� �ݺ�

		//�ѹ��� �� ����. ���� row���Ͽ��� ����� column�� �밢�� �� �ʱ�ȭ
		check[i] = 0;
		d[i + lev] = 0;
		d2[lev - i + 13] = 0;
	}
}

int solution2(int n, int k, int X[], size_t X_len, int Y[], size_t Y_len) {
	int answer = 0;
	int i, j;
	N = n;
	for (i = 0; i < k; i++)		//�־��� �Ұ����� ��ġ������ �ʱ�ȭ
		xy[X[i] - 1][Y[i] - 1] = 1;
	nqueen(0);
	answer = count;
	return answer;
}

int n, res;
int map[15];

bool isPromising(int r, int c) {
	for (int i = 1; i < r; i++) {
		if (map[i] == c)
			return false;
		if (abs(r - i) == abs(map[i] - c))
			return false;
	}
	return true;
}

void dfs(int r, int c) {
	map[r] = c;
	if (r == n) {
		res++;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (isPromising(r + 1, i)) {
				dfs(r + 1, i);
			}
		}
	}
	map[r] = 0;
}

int solution(int n, int k, int X[], size_t X_len, int Y[], size_t Y_len) {
	
}

int main(void) {
	int n = 4;
	int k = 2;
	int X[] = { 1, 1 };
	int Y[] = { 2, 3 };
	
	printf("\n%d", solution(n, k, X, k, Y, k));
}