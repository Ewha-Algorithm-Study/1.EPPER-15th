#include <stdio.h>

void solution() {
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 1������ 12��
	char days[15] = "���Ͽ�ȭ�����";

	int m, d;
	scanf_s("%d", &m);
	scanf_s("%d", &d);

	// 1�� 1�Ϻ��� �Է��� ��¥������ �� ��¥ ��
	int total_date = 0;
	for (int i = 0; i < m - 1; i++)
		total_date += month[i];
	total_date += d;

	int idx = total_date % 7 * 2; // ������ ����ؼ� ���� Ȯ��
	printf("%c%c����", days[idx], days[idx+ 1]); // �ѱ��� 2byte�� char 2���� print
	
}

int main() {
	solution();
}