#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	char str[100] = { 0, };
	scanf("%s", str);
	char key[7];
	scanf("%s", key);

	char ans[100];

	int str_len = 0;
	while (str[str_len] != '\0') //문자길이구하기
		str_len++;

	int i = 0;
	while (str_len % 7 != 0) {//abc채워넣기
		str[str_len+i] = (char)((int)'a' + i);
		i++; str_len++;
	}
	str[str_len] = '\0';

	for (int i = 0;i < str_len;i++) {
		ans[i] = str[7*(i/7)+(int)(key[i%7]-48) - 1];
	}

	for (int i = 0;i < str_len;i++)
		printf("%c", ans[i]);

}