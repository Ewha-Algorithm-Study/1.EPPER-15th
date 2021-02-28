#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996)
void hanoi(int n, char from, char to, char mid) {
	if (n == 0)
		return;

	hanoi(n - 1, from, mid, to);//제일아래있는 원판 빼고 나머지를 중간으로 옮김
	printf("%d: %c->%c\n", n, from, to);//제일아래있는 원판을 목적지로 옮김
	hanoi(n - 1, mid, to, from);//중간으로 옮긴 n-1개 원판을 목적지로 옮김

}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(n, 'A', 'C', 'B');
}