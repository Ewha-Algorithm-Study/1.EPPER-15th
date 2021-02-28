#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char alphabet[27]; // a���� z���� ������ �ִ� �迭
int each_count[16][26] = { 0 }; // �� ���ڿ��� ������ �ִ� ���ĺ� ����
int total_count[26] = { 0 }; // ��ü ���ڿ����� �� ���ĺ��� �� ����
int total_str[26] = { 0 }; // ��ü ���ڿ����� �� ���ĺ��� ������ �ִ� ���ڿ��� ����
int nodes = 0;


int solution() {
	
	// n�� str �Է� �ޱ�
	int n;
	scanf_s("%d", &n);
	char** str= (char**)malloc(sizeof(char*) * n); // �Է��� ���ڿ��� ���� n*1001 �迭
	char buffer[1001];
	for (int i = 0; i < n; i++) {
		scanf_s("%s", buffer, sizeof(buffer) + 1);
		str[i] = (char*)malloc(sizeof(char) * 1001);
		strcpy_s(str[i], 1001, buffer);
	}


	// str ���ĺ� ������� sort
	char tmp2;
	char* tmp3;
	for (int i = 0; i < n; i++) { // �� str �ȿ��� alphabetically
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
	for (int i = 0; i < n - 1; i++) { // ��ü str�� alphabetically
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


	// ���� �ٲ㼭 ���� str�� �ִ��� Ȯ�� -> �ִٸ� �����ϰ� str ���ġ
	int size = n;
	for (int i = 0; i < size - 1; i++) {
		if (strcmp(str[i], str[i + 1]) == 0) {
			for (int j = i + 1; j < size; j++) {
				if (j < size - 1)
					str[j] = str[j + 1];
				else
					str[size - 1] = NULL;
			}
			size--; // ��ü str ���� ����
		}
	}
	for (int i = 0; i < size; i++) {
		printf("<5>");
		printf("%s", str[i]);
		printf("\n");
	}


	// --------- ���ķ� str ������ : size ���� ��� ---------

	// �� str�� ���ĺ� ���� count
	int idx = 0;
	for (int i = 0; i < size; i++) {
		bool flag[26] = { false };
		for (int j = 0; j < strlen(str[i]); j++) {
			for (int k = 0; k < 26; k++) {
				if (str[i][j] == alphabet[k]) {
					total_count[k]++; // �� ���ĺ� ���� ��ü �� ���� �ִ���?
					each_count[idx][k]++; // �� ���ĺ� ����
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
				total_str[j]++; // �� ���ĺ��� ������ �ִ� str�� �� ������?
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

	
	// �˰��� ����
	while (1) {

		// �� ����ϸ� break
		for (int i = 0; i < 26; i++) {
			if (total_str[i] == 0 && total_count[i] == 0)
				break;
		}


		// �켱���� ���ϱ�
		int largest[3] = { 0 }; // ����� ���ĺ��� �ε���, total_str, total_count�� ���� ����
		for (int i = 0; i < 26; i++) { // ���� ū total_str ã��
			if (total_str[i] > largest[1]) {
				largest[0] = i;
				largest[1] = total_str[i];
			}
		}
		for (int i = 0; i < 25; i++) { // ���� total_str�� �ִ��� Ȯ�� -> ������ total_count ���ؼ� ū �� ���
			if (total_str[i] == largest[1] && i != largest[0]) {
				if (total_count[i] > total_count[largest[0]])
					largest[2] = total_count[i];
				else
					largest[2] = total_count[largest[0]];
			}
		}
		nodes++; // ��� �߰�


		total_str[largest[0]]--;
		total_count[largest[0]]--;
	}








	// �޸� ����
	//for (int i = 0; i < n; i++)
	//	free(str[i]);
	//free(str);
	

	return 1;
}

int main() {
	
	// a���� z�� initialize
	for (int i = 0; i < 26; i++)
		alphabet[i] = 'a' + i;


	printf("%d", solution());
}