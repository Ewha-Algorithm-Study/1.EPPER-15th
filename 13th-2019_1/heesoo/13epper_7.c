#include <stdio.h>
#pragma warning(disable:4996)

int count = 0;
int arr[10];

void solution(int s, int e) {
	if (s >= e) {
		return;
	}
	else if (arr[s] == arr[e]) {//같을때
		solution(s+1, e-1);
	}
	else if (arr[s] != arr[e]) {//다를때
		if (arr[s]<arr[e]) {//오른쪽이 더 크면
			count++;
			arr[s + 1] = arr[s] + arr[s + 1];//왼쪽 수를 키워줌
			solution(s + 1, e );
		}
		else  {//왼쪽이 더 크면
			count++;
			arr[e - 1] = arr[e] + arr[e - 1];//오른쪽 수를 키워줌
			solution(s , e - 1);
		}
	}
}

int main(void) {
	int n = 0;//요소 개수
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	solution(0, n - 1);
	printf("%d", count);
	return 0;
}

