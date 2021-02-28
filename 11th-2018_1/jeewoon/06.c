#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int solution() {
	int p, tmp, n = 0, answer = 0;
	int before[6] = { -1, -1, -1, -1, -1, -1 };
	int after[6] = { -1, -1, -1, -1, -1, -1 };
	scanf_s("%d", &p);

	// p�� �ڸ� �� ã��
	tmp = p;
	while (tmp != 0) {
		before[n] = tmp % 10;
		tmp /= 10;
		n++;
	}
	int start = 0, end = n - 1;
	while (start < end) { // �ݴ�� �� �ڸ��� ������
		tmp = before[start];
		before[start] = before[end];
		before[end] = tmp;
		start++;
		end--;
	}

	// recursive ����
	int point = n - 2; // �ٲ� �ڸ��� ����Ŵ
	while (point >= 0) {
		int* shuffle = (int*)malloc(sizeof(int) * (n - point)); // �ٲ� �ڸ��� �Ʒ��� �ִ� ���ڵ� array
		int shuf_size = n - point;
		bool flag = false;
		
		int idx = 0; // shuffle�� index
		for (int i = point; i < n; i++)
			shuffle[idx++] = before[i];
		
		// shuffle ������������ ����
		for (int i = 0; i < shuf_size - 1; i++) {
			for (int j = 0; j < shuf_size - 1 - i; j++) {
				if (shuffle[j] > shuffle[j + 1]) {
					int tmp = shuffle[j + 1];
					shuffle[j + 1] = shuffle[j];
					shuffle[j] = tmp;
					flag = true;
				}
			}
		}
		if (flag == false) { // �̹� shuffle�� ���ĵǾ������� point�� ���� (���� ���ڸ���)
			point--;
			continue;
		}


		// ���� �ڸ����� ū ���ڰ� �ؿ� ������ �־���
		flag = false;
		for (int i = 0; i < shuf_size; i++) {
			if (before[point] < shuffle[i]) {
				after[point] = shuffle[i];
				shuffle[i] = -1;
				flag = true;
				break;
			}
		}
		if (flag == false) { // ������ ���� ū ���� point�� ����
			point--;
			continue;
		}


		// ������ �� ���ġ
		for (int i = 0; i < point; i++) // point���� ����
			after[i] = before[i];
		for (int i = point + 1, idx = 0; i < n; i++) { // point���� ������
			if (shuffle[idx] == -1) {
				i--;
				idx++;
				continue;
			}
			if (idx < shuf_size)
				after[i] = shuffle[idx++];
		}

		break;
	}

	// after �迭�� �ڸ����� ���� answer ����
	for (int i = 0; i < 6; i++) {
		if (after[i] != -1) {
			answer += after[i] * pow(10.0, n - i - 1);
		}
	}
	if (answer == p) return 0;
	else return answer;
}

int main() {
	printf("%d", solution());
}
	