#include <stdio.h>
#pragma warning(disable:4996)

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int main() {
	int n; //돈의 개수
	scanf("%d", &n);
	int arr[30000];
	int dp[30000];
	int count = 0;
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]); //돈의 액수

	dp[0] = arr[0]; //n==1
	if (n > 1) 
		dp[1] = arr[0] + arr[1];
	if (n > 2)
		dp[2] = max(arr[1] + arr[2], dp[0] + arr[2]);
	count = max(dp[0], max(dp[1], dp[2]));//n==3
	for (int i = 3;i < n;i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]));
		//마지막 숫자 포함X , 마지막 숫자 포함O 중 최대
	
		count = max(dp[i], count);
	}
	printf("%d", count);

}