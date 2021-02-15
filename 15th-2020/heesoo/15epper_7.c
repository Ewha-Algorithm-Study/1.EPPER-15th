#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int s[], size_t s_len, int e[], size_t e_len) {
    int answer = 0;
    int N = s_len; //학생수
    int tmp;
    int e1 = -1, e2 = -1; // e1, e2는 각 자리

    //종료시간 1순위, 시작시간 2순위 기준으로 오름차순으로 정렬
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N - 1; j++) // 
        {
            if ((e[j] > e[j + 1]) || (e[j] == e[j + 1] && s[j] > s[j + 1]))
            { // 버블 정렬
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
                tmp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        if (e1 <= s[i]) // 시작시간이 e1의 종료시간보다 뒤에 있으므로 자리가 비어있다.
        {
            e1 = e[i]; // e1번 자리에 i번 학생의 종료 시간을 대입
            answer++; // 학생수 추가
        }

        else if (e2 <= s[i]) // e2자리가 비므로 학생 할당
        {
            e2 = e1; // 중복을 피하기 위해 1번 자리의 값을 2번으로 대입.
            e1 = e[i]; // e1번 자리에 i번 학생의 종료 시간을 대입합니다.
            answer++; // 학생수 추가
        }
    }

    return answer; 
}

int main() { 
    int s[] = { 1, 2, 3, 4, 5 };
    int e[] = { 2, 3, 4, 5, 6 };
    size_t s_len = sizeof(s) / 4;
    size_t e_len = sizeof(e) / 4;

    printf("%d \n", solution(s, s_len, e, e_len));
}