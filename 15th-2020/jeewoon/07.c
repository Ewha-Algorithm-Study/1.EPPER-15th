// 도서관 예약

// 모든 test case에 정답 나오지는 않음
// e-class 다 공개되면 코드 수정

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int s[], size_t s_len, int e[], size_t e_len) {
	int answer = 0, tmp_s, tmp_e;
	int e1 = -1, e2 = -1;

	for (int i = 0; i < s_len; i++) {
		for (int j = i + 1; j < s_len; j++) {
			if (s[i] > s[j]) {

				// 시작 시간 sorting
				tmp_s = s[i];
				s[i] = s[j];
				s[j] = tmp_s;

				// 끝나는 시간 sorting
				tmp_e = e[i];
				e[i] = e[j];
				e[j] = tmp_e;
			}
		}
	}

	for (int i = 0; i < s_len; i++) {
		// 1번 자리가 비어있는지 확인하고 채워넣기
		if (e1 <= s[i]) {
			e1 = e[i];
			answer++;
		}

		// 2번 자리가 비어있는지 확인하고 채워넣기
		else if (e2 <= s[i]) {
			e2 = e[i];
			answer++;
		}
	}

	return answer;
}

int main() {
	int s[] = { 30140, 23679, 17663, 8492, 9777, 17803, 55388, 7420, 23107, 37469 };
	int e[] = { 55374, 33664, 43614, 12763, 85637, 58156, 79170, 60252, 52676, 48022 };
	size_t s_len = sizeof(s) / 4;
	size_t e_len = sizeof(e) / 4;

	printf("%d", solution(s, s_len, e, e_len));
}