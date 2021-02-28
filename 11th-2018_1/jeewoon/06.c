#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int solution() {
	int p, tmp, n = 0, answer = 0;
	int before[6] = { -1, -1, -1, -1, -1, -1 };
	int after[6] = { -1, -1, -1, -1, -1, -1 };
	scanf_s("%d", &p);

	// p의 자릿 수 찾기
	tmp = p;
	while (tmp != 0) {
		before[n] = tmp % 10;
		tmp /= 10;
		n++;
	}
	int start = 0, end = n - 1;
	while (start < end) { // 반대로 된 자릿수 뒤집기
		tmp = before[start];
		before[start] = before[end];
		before[end] = tmp;
		start++;
		end--;
	}

	// recursive 시작
	int point = n - 2; // 바꿀 자릿수 가리킴
	while (point >= 0) {
		int* shuffle = (int*)malloc(sizeof(int) * (n - point)); // 바꿀 자릿수 아래에 있는 숫자들 array
		int shuf_size = n - point;
		bool flag = false;
		
		int idx = 0; // shuffle의 index
		for (int i = point; i < n; i++)
			shuffle[idx++] = before[i];
		
		// shuffle 오름차순으로 정렬
		for (int i = 0; i < shuf_size - 1; i++) {
			for (int j = 0; j < shuf_size - 1 - i; j++) {
				if (shuffle[j] > shuffle[j + 1]) {
					int tmp = shuffle[j + 1];
					shuffle[j + 1] = shuffle[j];
					shuffle[j] = tmp;
					flag = true;
				}
			}
		}
		if (flag == false) { // 이미 shuffle이 정렬되어있으면 point값 감소 (점점 앞자리로)
			point--;
			continue;
		}


		// 현재 자리보다 큰 숫자가 밑에 있으면 넣어줌
		flag = false;
		for (int i = 0; i < shuf_size; i++) {
			if (before[point] < shuffle[i]) {
				after[point] = shuffle[i];
				shuffle[i] = -1;
				flag = true;
				break;
			}
		}
		if (flag == false) { // 본인이 가장 큰 수면 point값 감소
			point--;
			continue;
		}


		// 나머지 수 재배치
		for (int i = 0; i < point; i++) // point보다 왼쪽
			after[i] = before[i];
		for (int i = point + 1, idx = 0; i < n; i++) { // point보다 오른쪽
			if (shuffle[idx] == -1) {
				i--;
				idx++;
				continue;
			}
			if (idx < shuf_size)
				after[i] = shuffle[idx++];
		}

		break;
	}

	// after 배열을 자릿수에 따라 answer 생성
	for (int i = 0; i < 6; i++) {
		if (after[i] != -1) {
			answer += after[i] * pow(10.0, n - i - 1);
		}
	}
	if (answer == p) return 0;
	else return answer;
}

int main() {
	printf("%d", solution());
}
	