#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//괄호개수를 구하여라
//앞에서부터 괄호개수를 셀때 왼쪽괄호개수보다 오른쪽괄호개수가 항상 적어야한다.

int sum = 0;
int func(as, bs, level,n) {
	if (as < bs)
		return 0;
	if (as > n || bs > n)
		return 0;

	if (level == n * 2) {
		return sum = sum + 1;//개수추가
	}
	func(as + 1, bs, level + 1, n);//왼쪽 괄호 더 넣을때
	func(as, bs + 1, level + 1, n);//오른쪽 괄호 하나 더 넣을때
}
int main() {
	int n;
	scanf("%d", &n);
	int l = 0, r = 0;
	func(l, r, 0, n);
	printf("%d", sum);
	
}