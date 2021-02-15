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
		if (s >= e) // 시작점이 끝점 넘어가면 break
			break;

		if (arr[s] == arr[e]) { // 두 요소가 같을 경우 skip
			s++;
			e--;
		}
		else if (arr[s] < arr[e]) { // 앞쪽 요소가 뒷쪽 요소보다 작을 경우 -> 앞쪽 두개 더하기
			arr[s + 1] = arr[s] + arr[s + 1];
			count++;
			s++;
		}
		else if (arr[s] > arr[e]) { // 뒷쪽 요소가 앞쪽 요소보다 클 경우 -> 뒤쪽 두개 더하기
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