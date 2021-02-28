#include <stdio.h>
#include <stdlib.h>

int solution() {

    int n, k, t;
    int time = 0;
    scanf_s("%d", &n);
    int arr[50][50] = { 0 };
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf_s("%d", &t);
            arr[t][i] = 1;
            if (time < t)
                time = t;
        }
    }

    int mid = (n - 1) / 2; // �߰����� ���
    // ���� �ڸ����� �����°� -1�� �ʱ�ȭ
    for (int i = 1; i < mid; i++) {
        for (int j = 1; j <= mid - i; j++)
            arr[i][j] = -1;
        for (int j = mid + i; j <= n; j++)
            arr[i][j] = -1;
    }

    // arr[][] ������Ʈ
    for (int i = 2; i <= time; i++) {
        for (int j = 1; j <= n; j++) {

            // ���� �� �� �ִ� �ڸ� ��
            if (arr[i][j] != -1) {
                int max = 0;
                for (int m = -1; m <= 1; m++) {
                    if (j + m >= 1 && j + m <= n) {
                        if (max < arr[i - 1][j + m]) // �ִ밪 ����
                            max = arr[i - 1][j + m];
                    }
                }
                arr[i][j] += max;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
        if (arr[time][i] > answer)
            answer = arr[time][i];

    return answer;
}

int main(void) {

    printf("%d", solution());
}