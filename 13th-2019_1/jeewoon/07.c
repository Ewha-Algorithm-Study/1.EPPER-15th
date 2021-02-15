#include <stdio.h>
#include <stdlib.h>

int solution() {
	int n;
	int arr[10];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);

	int s = 0, e = n - 1;
	int count = 0;
	while (1) {
		if (s >= e) // �������� ���� �Ѿ�� break
			break;

		if (arr[s] == arr[e]) { // �� ��Ұ� ���� ��� skip
			s++;
			e--;
		}
		else if (arr[s] < arr[e]) { // ���� ��Ұ� ���� ��Һ��� ���� ��� -> ���� �ΰ� ���ϱ�
			arr[s + 1] = arr[s] + arr[s + 1];
			count++;
			s++;
		}
		else if (arr[s] > arr[e]) { // ���� ��Ұ� ���� ��Һ��� Ŭ ��� -> ���� �ΰ� ���ϱ�
			arr[e - 1] = arr[e] + arr[e - 1];
			count++;
			e--;
		}
	}
	
	return count;

}

int main() {
	printf("%d", solution());
}