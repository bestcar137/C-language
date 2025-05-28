/// DCU 자료구조 10 - 2 : DFS와 BFS를 이용한 그래프 탐색 (인접 리스트 기반)

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 1001   // 문제 조건에 따라 최대 정점 수는 1000개

// ------------------------------
// 그래프 인접 리스트 노드 구조체 정의
// ------------------------------
typedef struct GraphNode {
    int vertex; // 연결된 정점 번호
    struct GraphNode *link; // 다음 인접 노드를 가리키는 포인터
} GraphNode;

// ------------------------------
// 그래프 구조체 (정점 배열 + 방문 배열)
// ------------------------------
typedef struct {
    GraphNode *adj_list[MAX_VERTICES]; // 각 정점에 대한 인접 리스트의 시작 포인터
    int visited[MAX_VERTICES]; // 정점 방문 여부 저장 배열 (DFS, BFS 공용)
} GraphType;

// ------------------------------
// 큐 구조체 (BFS에 사용)
// ------------------------------
typedef struct {
    int queue[MAX_VERTICES]; // 정수를 저장하는 큐 배열
    int front, rear; // 큐의 front, rear 포인터
} Queue;

// ------------------------------
// 그래프 초기화 함수
// ------------------------------
void init_graph(GraphType *g, int n) {
    for (int i = 1; i <= n; i++) {
        g->adj_list[i] = NULL; // 인접 리스트 초기화
        g->visited[i] = 0; // 방문 배열 0으로 초기화
    }
}

// ------------------------------
// 간선 삽입 함수 (무방향 그래프이므로 양방향으로 삽입)
// ------------------------------
void insert_edge(GraphType *g, int u, int v) {
    // u → v 연결
    GraphNode *node = (GraphNode *) malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;

    // v → u 연결
    node = (GraphNode *) malloc(sizeof(GraphNode));
    node->vertex = u;
    node->link = g->adj_list[v];
    g->adj_list[v] = node;
}

// ------------------------------
// 인접 리스트 정렬 함수
// 각 정점의 인접 리스트를 정점 번호 오름차순으로 정렬
// 삽입 정렬 방식으로 수행
// ------------------------------
void sort_adj_list(GraphType *g, int n) {
    for (int i = 1; i <= n; i++) {
        GraphNode *sorted = NULL;
        GraphNode *current = g->adj_list[i];

        while (current) {
            GraphNode *next = current->link;

            // 정점 번호가 작으면 리스트 앞에 삽입
            if (!sorted || current->vertex < sorted->vertex) {
                current->link = sorted;
                sorted = current;
            } else {
                // 중간 또는 끝에 삽입
                GraphNode *temp = sorted;
                while (temp->link && temp->link->vertex < current->vertex)
                    temp = temp->link;
                current->link = temp->link;
                temp->link = current;
            }

            current = next;
        }

        g->adj_list[i] = sorted;
    }
}

// ------------------------------
// 깊이 우선 탐색 (DFS) - 재귀 방식
// ------------------------------
void dfs(GraphType *g, int v) {
    g->visited[v] = 1; // 현재 정점 방문 표시
    printf("%d ", v); // 정점 출력

    // 인접한 모든 정점 탐색
    for (GraphNode *w = g->adj_list[v]; w; w = w->link) {
        if (!g->visited[w->vertex])
            dfs(g, w->vertex); // 미방문 정점에 대해 재귀 호출
    }
}

// ------------------------------
// 큐 초기화
// ------------------------------
void init_queue(Queue *q) {
    q->front = q->rear = -1;
}

// ------------------------------
// 큐 삽입 연산
// ------------------------------
void enqueue(Queue *q, int v) {
    q->queue[++(q->rear)] = v;
}

// ------------------------------
// 큐 삭제 연산
// ------------------------------
int dequeue(Queue *q) {
    return q->queue[++(q->front)];
}

// ------------------------------
// 큐가 비었는지 확인
// ------------------------------
int is_empty(Queue *q) {
    return q->front == q->rear;
}

// ------------------------------
// 너비 우선 탐색 (BFS)
// ------------------------------
void bfs(GraphType *g, int v, int n) {
    Queue q;
    init_queue(&q);

    g->visited[v] = 1; // 시작 정점 방문
    enqueue(&q, v); // 큐에 시작 정점 삽입

    while (!is_empty(&q)) {
        int x = dequeue(&q); // 큐에서 정점 추출
        printf("%d ", x); // 정점 출력

        // 해당 정점에 인접한 정점 순회
        for (GraphNode *w = g->adj_list[x]; w; w = w->link) {
            if (!g->visited[w->vertex]) {
                g->visited[w->vertex] = 1;
                enqueue(&q, w->vertex);
            }
        }
    }
}

// ------------------------------
// 메인 함수
// ------------------------------
int main() {
    GraphType g;
    int n, m, v;

    // 정점 수(n), 간선 수(m), 탐색 시작 정점 번호(v) 입력
    scanf("%d %d %d", &n, &m, &v);

    // 그래프 초기화
    init_graph(&g, n);

    // 간선 정보 입력 및 저장
    for (int i = 0; i < m; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        insert_edge(&g, u, w);
    }

    // DFS/BFS를 위해 인접 리스트 정렬 (작은 번호부터 탐색)
    sort_adj_list(&g, n);

    // 깊이 우선 탐색 수행 및 출력
    dfs(&g, v);
    printf("\n");

    // BFS를 위해 방문 배열 초기화
    for (int i = 1; i <= n; i++)
        g.visited[i] = 0;

    // 너비 우선 탐색 수행 및 출력
    bfs(&g, v, n);
    printf("\n");

    return 0;
}
