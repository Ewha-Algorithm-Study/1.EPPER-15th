//사각형을 완성하기 위한 마지막 점의 좌표 구하기
//사각형을 이루는 네가지 좌표는 x좌표 y좌표 각각 중복이 두개씩 있다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int arr[3][2];
	int count = 1;//중복 구분
	int res[2];
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 2;j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0;i < 2;i++) {
		int fst = arr[0][i];
		if (arr[1][i] != fst) {//첫번째 수와 두번째 수가 다르면
			if (arr[2][i] != fst)//세번째 수가 첫번째 수와 다르면
				res[i] = fst;//결과x값에 첫번째 수 대입
			else
				res[i] = arr[1][i];
		}
		else
			res[i] = arr[2][i];//첫번째수와 두번째수가 같으면 결과값은 세번째수와 같다.
	}

	printf("%d %d", res[0], res[1]);
	
}