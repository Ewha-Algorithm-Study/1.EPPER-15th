#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char alphabet[27]; // a부터 z까지 가지고 있는 배열
int each_count[16][26] = { 0 }; // 각 문자열별 가지고 있는 알파벳 개수
int total_count[26] = { 0 }; // 전체 문자열에서 각 알파벳의 총 개수
int total_str[26] = { 0 }; // 전체 문자열에서 각 알파벳을 가지고 있는 문자열의 개수
int nodes = 0;


int solution() {
	
	// n과 str 입력 받기
	int n;
	scanf_s("%d", &n);
	char** str= (char**)malloc(sizeof(char*) * n); // 입력한 문자열이 들어가는 n*1001 배열
	char buffer[1001];
	for (int i = 0; i < n; i++) {
		scanf_s("%s", buffer, sizeof(buffer) + 1);
		str[i] = (char*)malloc(sizeof(char) * 1001);
		strcpy_s(str[i], 1001, buffer);
	}


	// str 알파벳 순서대로 sort
	char tmp2;
	char* tmp3;
	for (int i = 0; i < n; i++) { // 각 str 안에서 alphabetically
		for (int j = 0; j < strlen(str[i]) - 1; j++) {
			for (int k = j + 1; k < strlen(str[i]); k++) {
				if (str[i][j] > str[i][k]) {
					tmp2 = str[i][j];
					str[i][j] = str[i][k];
					str[i][k] = tmp2;
				}
			}
		}
	}
	for (int i = 0; i < n - 1; i++) { // 전체 str을 alphabetically
		if (strcmp(str[i], str[i + 1]) > 0) {
			tmp3 = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp3;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("<5>");
		printf("%s", str[i]);
		printf("\n");
	}
	printf("\n");


	// 순서 바꿔서 같은 str이 있는지 확인 -> 있다면 제거하고 str 재배치
	int size = n;
	for (int i = 0; i < size - 1; i++) {
		if (strcmp(str[i], str[i + 1]) == 0) {
			for (int j = i + 1; j < size; j++) {
				if (j < size - 1)
					str[j] = str[j + 1];
				else
					str[size - 1] = NULL;
			}
			size--; // 전체 str 개수 조정
		}
	}
	for (int i = 0; i < size; i++) {
		printf("<5>");
		printf("%s", str[i]);
		printf("\n");
	}


	// --------- 이후로 str 사이즈 : size 변수 사용 ---------

	// 각 str별 알파벳 개수 count
	int idx = 0;
	for (int i = 0; i < size; i++) {
		bool flag[26] = { false };
		for (int j = 0; j < strlen(str[i]); j++) {
			for (int k = 0; k < 26; k++) {
				if (str[i][j] == alphabet[k]) {
					total_count[k]++; // 각 알파벳 별로 전체 몇 개가 있는지?
					each_count[idx][k]++; // 각 알파벳 저장
					flag[k] = true;
					//printf("o ");
				}
				//else printf("x ");
			}
		}
		//printf("\n");
		idx++;
		for (int j = 0; j < 26; j++) {
			if (flag[j] == true)
				total_str[j]++; // 각 알파벳을 가지고 있는 str은 몇 개인지?
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 26; j++)
			printf("%d ", each_count[i][j]);
		printf("\n");
	}
	for (int i = 0; i < 26; i++) {
		printf("%c : %d, %d\n", alphabet[i], total_count[i], total_str[i]);
	}

	
	// 알고리즘 시작
	while (1) {

		// 다 사용하면 break
		for (int i = 0; i < 26; i++) {
			if (total_str[i] == 0 && total_count[i] == 0)
				break;
		}


		// 우선순위 정하기
		int largest[3] = { 0 }; // 사용할 알파벳의 인덱스, total_str, total_count값 각각 담음
		for (int i = 0; i < 26; i++) { // 가장 큰 total_str 찾기
			if (total_str[i] > largest[1]) {
				largest[0] = i;
				largest[1] = total_str[i];
			}
		}
		for (int i = 0; i < 25; i++) { // 같은 total_str가 있는지 확인 -> 있으면 total_count 비교해서 큰 값 사용
			if (total_str[i] == largest[1] && i != largest[0]) {
				if (total_count[i] > total_count[largest[0]])
					largest[2] = total_count[i];
				else
					largest[2] = total_count[largest[0]];
			}
		}
		nodes++; // 노드 추가


		total_str[largest[0]]--;
		total_count[largest[0]]--;
	}








	// 메모리 해제
	//for (int i = 0; i < n; i++)
	//	free(str[i]);
	//free(str);
	

	return 1;
}

int main() {
	
	// a부터 z로 initialize
	for (int i = 0; i < 26; i++)
		alphabet[i] = 'a' + i;


	printf("%d", solution());
}