#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#pragma warning(disable:4996)

#define inf 1<<30
#define MAX 1<<20
int n;
char str[16][16]; //접두어 배열
int count[16][26]; //접두어의 알파벳 개수
int dp[1 << 16]; 

int calc_pref(int mask) {
	int len = 0;
	int tmp[26]; 
	for (int i = 0;i < 26;i++)
		tmp[i] = inf;

	for (int i = 0;i < n;i++) {
		if (mask & (1 << i))
			for (int j = 0;j < 26;j++)
				tmp[j] = (tmp[j] > count[i][j]) ? count[i][j] : tmp[j];

	}
	for (int i = 0;i < 26;i++)
		len += tmp[i];
	return len;
}

int solve(int mask) {
	int* ret = &dp[mask];

	if (*ret != -1)
		return *ret;

	int pref = calc_pref(mask);
	if ((mask & -mask) == mask)
		return *ret = pref;
	*ret = inf;
	for (int i = (mask - 1) & mask; i > 0;i = (i - 1) & mask) {
		int curr = solve(i) + solve(mask ^ i) - pref;
		*ret = (*ret > curr) ? curr : *ret;
	}
	return *ret;
}
int main(void) {
	memeset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%s", str[i]);

	for (int i = 0;i < n;i++) {
		for (int j = 0;str[i][j];j++)
			count[i][str[i][j] - 'a']++;
	}
	printf("%d\n", solve((1 << n) - 1) + 1);
}