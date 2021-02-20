#include <stdio.h>

int solution(int left, int right) {
	if (left == 0 && right == 0) // ������, ���� ��ȣ ��� ����� ���
		return 1;
	else {
		if (left == 0) // ���� ��ȣ ���� ����� ��� -> ������ ��ȣ�� ���� ��� �ϴ� ��� 1����
			return 1;
		else if (left < right) // ���� ��ȣ�� ������ ��ȣ���� ���� ��� -> �� �� �ƹ��ų� ��밡��
			return solution(left - 1, right) + solution(left, right - 1);
		else // ���� ��ȣ�� ������ ��ȣ ���� ��� -> ���� ��ȣ�� ��� ����
			return solution(left - 1, right);
	}
}

int main() {
	int n, count = 0;

	scanf_s("%d", &n);
	printf("%d", solution(n, n));
}