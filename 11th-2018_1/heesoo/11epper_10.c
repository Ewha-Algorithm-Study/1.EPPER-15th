#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int arr[1000][100000] = { 0, }; //[i번째 정사각형][사과 떨어지는 시간]
int sum = 0;
int func(int index, int N, int time,int max_t) {
	if (time > max_t)
		return sum;
	if (arr[index][time] == 1)
		sum += 1;
	if (index > 0)
		func(index - 1, N, time + 1, max_t);
	if (index < N - 1)
		func(index + 1, N, time + 1, max_t);
	func(index, N, time + 1, max_t);
}
int main() {
	int N;//정사각형 개수
	scanf("%d", &N);
	int k;//떨어지는 횟수
	int t;//떨어지는 시간
	int max_t = 0;
	for (int i = 0;i < N;i++) {
		scanf("%d", &k);
		for (int j = 0;j < k;j++) {
			scanf("%d", &t);
			if (max_t < t)
				max_t = t;
			arr[i][t] = 1;
		}
	}

	func(N / 2 + 1, N, 0, max_t);
	printf("%d", sum);


	

}