// ���ڿ�����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
	char* answer = (char*)malloc(strlen(s));
	int j = 0, count = 0;

	for (int i = 0; i < strlen(s)-1; i++) {
		
		// ��Ʈ�� ������ 1�� ��� ���� �տ� 1 ���̱�
		if (s[0] == 1)
			answer[j++] = '1';

		// �յ� ���� ������ ��� count�� ��� �ݺ����� ����
		if (s[i] == s[i + 1]) {
			count++;
		}
		// ���� ���� �ƴ� ��� count��ŭ ���ĺ� ����
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