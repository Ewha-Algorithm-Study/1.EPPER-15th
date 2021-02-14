// 문자열압축

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
	char* answer = (char*)malloc(strlen(s));
	int j = 0, count = 0;

	for (int i = 0; i < strlen(s)-1; i++) {
		
		// 비트열 시작이 1인 경우 가장 앞에 1 붙이기
		if (s[0] == 1)
			answer[j++] = '1';

		// 앞뒤 같은 숫자일 경우 count에 몇번 반복인지 저장
		if (s[i] == s[i + 1]) {
			count++;
		}
		// 같은 숫자 아닐 경우 count만큼 알파벳 저장
		else {
			answer[j++] = 'A' + count;
			count = 0;
		}

	}

	return answer;
}

int main() {
	char* answer = solution("000");
	printf("%s", answer);
}