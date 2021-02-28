#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	char* names[50];
	char buffer[30];
	int k = 0;
	for (int i = 0;i < n;i++) {
		scanf("%s", buffer);
		//버퍼에 문자열을 입력받은후, 
		//그 길이 만큼 새 문자열을 위한 메모리를 할당한다.
		//새로 할당된 메모리에 버퍼의 내용을 복사하고 그 시작 위치를 배열에 추가
		k = strlen(buffer);
		if (k > 0) {
			char* newstr = (char*)malloc(sizeof(char) * (k + 1));
			strcpy(newstr, buffer);
			names[i] = newstr;
		}
		else {
			break;
		}
	}
	for (int i = 0;i < n;i++) {
		printf("Hello, %s!\n",names[i]);
	}
	return 0;
	
}

