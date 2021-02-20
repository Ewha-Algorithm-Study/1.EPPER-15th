#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 16 // 최대 문자열 개수
#define MAXL 1001 // 최대 문자열 길이
#define INF 999999999 // INFINITY로 어떤 수와 비교해도 가장 큰 수

int cnt[MAXN][26]; // 문자열의 a~z 26개의 알파벳 개수
int dp[1 << MAXN]; // 최대 문자열 조합 경우의 수 2^16만큼 필요


// 문자열 조합 x에서 중복 알파벳 개수 계산합니다.
int calc_pref(int n, int x) {
	int len = 0; // 중복 알파벳 개수
	int temp[26]; // 알파벳별로 최소로 존재하는 개수 저장
	// temp배열을 최댓값으로 초기화합니다.
	for (int i = 0; i < 26; i++) {
		temp[i] = INF;
	}
	for (int i = 0; i < n; i++) {
		if (x & (1 << i)) // i번째 문자열 포함 확인합니다.
			for (int j = 0; j < 26; j++)
				// temp[j]와 cnt[i][j]중 작은 값 선택합니다.
				temp[j] = (temp[j] > cnt[i][j]) ? cnt[i][j] : temp[j];
	}
	// temp 전부 더합니다.
	for (int i = 0; i < 26; i++)
		len += temp[i];
	return len;
}


int solve(int n, int x) {
	// 한 번 계산한 dp는 다시 계산하지 않고 이전 계산 결과 활용
	if (dp[x] != -1) return dp[x];

	// 문자열 조합 x에서 모두 중복되는 알파벳 개수를 계산합니다.
	int pref = calc_pref(n, x);
	// x가 2의 제곱수인지 확인
	// => 문자열 1개만 포함한 조합인 경우,
	// 해당 문자열의 알파벳 개수 리턴
	if ((x & -x) == x) return dp[x] = pref;
	// 모든 문자열 조합 모두 순회
	dp[x] = INF;
	for (int i = (x - 1) & x; i > 0; i = (i - 1) & x) {
		int curr = solve(n, i) + solve(n, x ^ i) - pref;
		dp[x] = (dp[x] > curr) ? curr : dp[x];
	}
	return dp[x];
}

int solution(int n, char str[][1001])
{
	// dp배열 -1로 초기화합니다.
	memset(dp, -1, sizeof(dp));

	// i번째 문자열의 알파벳 개수를 인덱스에 맞추어 모두 저장합니다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; str[i][j]; j++) {
			cnt[i][str[i][j] - 'a']++;
		}
	}
	return solve(n, (1 << n) - 1) + 1;
} // solve(2^n-1) 실행 후 +1

int main() {
	char str[][1001] = { 'a', 'ab', 'abc' };
	printf("%d", solution(3, str));
}
