// n���� �۾�����

#include <stdio.h>
#define MAX 101

int adj[MAX][MAX] = { 0, };
int indegree[MAX] = { 0, };
int time[MAX] = { 0, };

int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct {
    int head;
    int tail;
    int arr[MAX];
} queue;

// ť �Լ� ����
int isQueueEmpty(queue q) {
    if (q.head == q.tail) return 1;
    return 0;
}

void enqueue(queue* q, int data) {
    q->arr[q->head++] = data;
}

int dequeue(queue* q) {
    if (isQueueEmpty(*q)) {
        printf("the queue is empty!\n");
        return -1;
    }
    int data = q->arr[q->tail++];
    return data;
}

int solution(int n[], int r[][100], int goal, int N, int R) {
    queue q;

    // ť �ʱ�ȭ
    q.head = 0;
    q.tail = 0;

    // ������İ� ������ �ʱ�ȭ
    for (int i = 0; i < R; i++) {
        int u = r[i][0];
        int v = r[i][1];
        adj[u][v] = 1;
        indegree[v]++;
    }

    // ��������(������)�� 0�� �������� ť�� �ִ´�
    // ���������� 0�� �����̶�� ���� �ش� ���� ���� �����ؾ��ϴ� ������ ���ٴ� ���̴�
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            // �����ؾ��ϴ� ������ ���� ������ ��� �ҿ�ð��� �ڱ� �ڽ��� �ҿ� �ð��� �������ָ� �ȴ�
            // n[i]�� �ƴϰ� n[i-1]�� ������ n�� 0�� �ε����� 1�� ���� �ҿ�ð��� ����Ǿ� �ֱ� �����̴�
            time[i] = n[i - 1];
            enqueue(&q, i);
        }
    }

    // ť�� �� ������ ������ ����(�������)�� �����ϰ� ���� ������ �����Ѵ�
    // ���� ���ſ� ���� ������ ���� �ϸ� ���� �ҿ�ð��� ������Ʈ�Ѵ�
    // ���������� 0�� �� ������ ť�� �ִ´�
    // ���� ������ ��� ������ ó���� ������ �ݺ��Ѵ�
    while (!isQueueEmpty(q)) {
        int p = dequeue(&q); // ���������� 0�� ����
        for (int i = 1; i <= N; i++) {
            // �̹��� ó���ϴ� ������ i�� ���� ���� �����ؾ� �ϴ� �����̶��
            // i�� ���� ���� �����ؾ��ϴ� p�� �������� �ҿ�Ǵ� �ð� + i�� ���� �ܵ� �ҿ�ð���
            // ���ݱ��� ���� i�� �������� �ҿ�ð��� ���ؼ� �� ū �ɷ� ������Ʈ�Ѵ�
            if (adj[p][i] == 1) {
                time[i] = max(time[i], time[p] + n[i - 1]);
                indegree[i]--;
                if (indegree[i] == 0) enqueue(&q, i);
            }
        }
    }

    return time[goal];
}

int main() {
    int N;
    int R;
    int n[100] = { 0 };
    int r[100][100] = { 0 };
    int goal, k;

    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    for (int k = 0; k < R; k++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &r[k][j]);
        }
    }

    scanf("%d", &goal);
    k = solution(n, r, goal, N, R);
    printf("%d\n", k);
}