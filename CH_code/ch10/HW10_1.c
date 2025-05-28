/// DCU 자료구조 10 - 1 : 미로 최단 경로 탐색 (BFS 기반)

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

// ------------------------------
// 방향 벡터 정의 (상, 하, 좌, 우)
// 각 방향으로 이동할 때 사용할 좌표 증가량
// ------------------------------
int dx[4] = {-1, 1, 0, 0}; // 행 방향
int dy[4] = {0, 0, -1, 1}; // 열 방향

int maze[MAX_VERTICES][MAX_VERTICES]; // 미로 정보 저장 배열 (1: 이동 가능, 0: 벽)
int visited[MAX_VERTICES][MAX_VERTICES]; // 방문 및 거리 저장 배열
int n, m; // 미로의 행(n)과 열(m) 크기

// ------------------------------
// 위치 정보를 담는 구조체 (좌표용)
// ------------------------------
typedef struct {
    int x, y; // 현재 위치의 행(x), 열(y)
} Point;

// ------------------------------
// 큐 구조체 (BFS 구현용)
// ------------------------------
typedef struct {
    Point data[MAX_VERTICES * MAX_VERTICES]; // 큐에 저장되는 좌표 정보
    int front, rear; // 큐 포인터
} Queue;

// ------------------------------
// 큐 초기화 함수
// ------------------------------
void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// ------------------------------
// 큐 삽입 함수
// 큐의 rear에 새 좌표를 추가
// ------------------------------
void enqueue(Queue *q, Point item) {
    q->data[++(q->rear)] = item;
}

// ------------------------------
// 큐 삭제 함수
// front 포인터가 가리키는 요소를 반환
// ------------------------------
Point dequeue(Queue *q) {
    return q->data[++(q->front)];
}

// ------------------------------
// 큐 공백 확인 함수
// front와 rear가 같으면 큐가 비어있음
// ------------------------------
int is_empty(Queue *q) {
    return q->front == q->rear;
}

// ------------------------------
// BFS 알고리즘 구현 함수
// 시작점 (0,0)에서 끝점 (n-1,m-1)까지 최단 거리 탐색
// ------------------------------
int bfs(int start_x, int start_y) {
    Queue q;
    init_queue(&q);

    visited[start_x][start_y] = 1; // 시작점 방문 및 거리 1로 설정
    enqueue(&q, (Point){start_x, start_y}); // 시작점 큐에 삽입

    while (!is_empty(&q)) {
        Point p = dequeue(&q); // 현재 위치 추출
        int x = p.x;
        int y = p.y;

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // 다음 x 위치
            int ny = y + dy[i]; // 다음 y 위치

            // 미로 범위 안에 있고, 이동 가능한 길(1)이며, 아직 방문하지 않은 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maze[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1; // 현재까지 거리 + 1 저장
                    enqueue(&q, (Point){nx, ny}); // 다음 위치를 큐에 삽입
                }
            }
        }
    }

    return visited[n - 1][m - 1]; // 도착점까지의 거리 반환
}

// ------------------------------
// 메인 함수
// 미로 입력 → BFS 호출 → 결과 출력
// ------------------------------
int main() {
    scanf("%d %d", &n, &m); // 미로의 행(n), 열(m) 입력
    char input[MAX_VERTICES]; // 문자열 형태로 한 줄씩 입력받기 위함

    // 미로 정보 입력 처리
    for (int i = 0; i < n; i++) {
        scanf("%s", input); // 한 줄 문자열 입력
        for (int j = 0; j < m; j++) {
            maze[i][j] = input[j] - '0'; // 문자 '1', '0'을 정수 1, 0으로 변환
            visited[i][j] = 0; // 방문 배열 초기화
        }
    }

    // BFS 실행 후 결과 출력
    int result = bfs(0, 0); // 시작점 (0,0) 기준
    printf("%d\n", result); // 도착점까지의 최소 이동 칸 수 출력
    return 0;
}
