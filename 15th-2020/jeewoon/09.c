// n개의 작업공정

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

// 큐 함수 구현
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

    // 큐 초기화
    q.head = 0;
    q.tail = 0;

    // 인접행렬과 내차수 초기화
    for (int i = 0; i < R; i++) {
        int u = r[i][0];
        int v = r[i][1];
        adj[u][v] = 1;
        indegree[v]++;
    }

    // 진입차수(내차수)가 0인 공정들을 큐에 넣는다
    // 진입차수가 0인 공정이라는 것은 해당 공정 전에 선행해야하는 공정이 없다는 뜻이다
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            // 선행해야하는 공정이 없는 공정의 경우 소요시간을 자기 자신의 소요 시간만 생각해주면 된다
            // n[i]가 아니고 n[i-1]인 이유는 n의 0번 인덱스에 1번 공정 소요시간이 저장되어 있기 때문이다
            time[i] = n[i - 1];
            enqueue(&q, i);
        }
    }

    // 큐에 들어간 공정에 부착된 에지(선행관계)를 제거하고 진입 차수를 재계산한다
    // 에지 제거와 진입 차수를 재계산 하며 공정 소요시간을 업데이트한다
    // 진입차수가 0이 된 공정을 큐에 넣는다
    // 위의 과정을 모든 공정을 처리할 때까지 반복한다
    while (!isQueueEmpty(q)) {
        int p = dequeue(&q); // 진입차수가 0인 공정
        for (int i = 1; i <= N; i++) {
            // 이번에 처리하는 공정이 i번 공정 전에 진행해야 하는 공정이라면
            // i번 공정 전에 선행해야하는 p번 공정까지 소요되는 시간 + i번 공정 단독 소요시간과
            // 지금까지 계산된 i번 공정까지 소요시간을 비교해서 더 큰 걸로 업데이트한다
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