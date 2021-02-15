// ��������

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int(*point)[10]) {
    int m = 50;
    int cache[20][20]; 
    int(*result)[10];
    int i, j, o;
    int ret = 0, gap, gap2;

    // �迭 �ʱ�ȭ
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            cache[i][j] = m;
            result[i][j] = 2;
        }
    }

    // ������ ���� ��� ó���ϱ�
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            ret = 0, gap;
            for (o = 0; o < 10; o++) {
                // ret ���� point �� i ���� i ���� �� ����
                // ��, point[i][i] ��ġ�� �л����� �������� �� ������ �޴� ��ҵ��� ����
                ret += point[i][o];
                ret += point[o][j];
            }
            
            gap = ret - point[i][j];
            if (gap % 2) {
                result[i][j] = 3; // point[i][j] ��ġ�� �л��� ������ ����
                for (o = 0; o < 10; o++) {
                    // ĳ�� �迭���� �ش� ��� �ݿ�
                    cache[i][o]++;
                    cache[o][j]++;
                }
                cache[i][j]--; // �ι� ������ ���̹Ƿ� -1
            }
        }
    }
    // ������ Ʋ�� ��� ó���ϱ�
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            ret = 0;
            for (o = 0; o < 10; o++) {
                ret += point[i][o];
                ret += point[o][j];
            }
            //���� ������ ������ �����Ͽ� gap �� ����
            gap = ret - point[i][j];
            ret = 0;
            // ��, ������ ���߰ų� Ʋ�� �л��� ������ �� �Ǵ� �࿡ ��ġ�� �л��� ���� ������ �˱� ������
            // cache ���� �ٽ� ���Ͽ� ret �� 
            for (o = 0; o < 10; o++) {
                ret += cache[i][o];
                ret += cache[o][j];
            }
            gap2 = ret - cache[i][j];
            gap -= gap2;
            gap = gap % 4 < 0 ? gap % 4 + 4 : gap % 4;
            // point[i][j] ��ġ�� �л��� ������ Ʋ��
            if (gap == 2)
                result[i][j] = 1;
        }
    }
    return (int*)result;
}

int main() {
    int input[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            scanf("%d", &input[i][j]);
    }
 
    int(*answer)[10] = solution(input);
    
    // ���
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%d ", answer[i][j]);
        printf("\n");
    }
}