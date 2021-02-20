#include <stdio.h>

int solution(int left, int right) {
	if (left == 0 && right == 0) // 오른쪽, 왼쪽 괄호 모두 사용한 경우
		return 1;
	else {
		if (left == 0) // 왼쪽 괄호 전부 사용한 경우 -> 오른쪽 괄호를 전부 사용 하는 방법 1가지
			return 1;
		else if (left < right) // 왼쪽 괄호가 오른쪽 괄호보다 적은 경우 -> 둘 중 아무거나 사용가능
			return solution(left - 1, right) + solution(left, right - 1);
		else // 왼쪽 괄호와 오른쪽 괄호 같은 경우 -> 왼쪽 괄호만 사용 가능
			return solution(left - 1, right);
	}
}

int main() {
	int n, count = 0;

	scanf_s("%d", &n);
	printf("%d", solution(n, n));
}