/// DCU 자료구조 10 - 3 : DFS를 이용한 단지 번호 붙이기

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25   // 최대 지도 크기 (문제 조건: 5 ≤ N ≤ 25)

int map[MAX_SIZE][MAX_SIZE]; // 지도 정보 (1: 집 있음, 0: 공터)
int visited[MAX_SIZE][MAX_SIZE]; // 방문 여부 기록 배열
int n; // 지도 크기 (n x n)
int complex_sizes[MAX_SIZE * MAX_SIZE]; // 각 단지의 집 수 저장 배열
int complex_count = 0; // 단지 개수

// 상하좌우 방향으로 탐색하기 위한 좌표 변화 배열
int dx[4] = {-1, 1, 0, 0}; // 행 방향 (상, 하)
int dy[4] = {0, 0, -1, 1}; // 열 방향 (좌, 우)

// ------------------------------
// DFS 함수: 현재 위치에서 연결된 모든 집(1)을 탐색
// 연결된 집들을 하나의 단지로 보고 그 크기를 반환
// ------------------------------
int dfs(int x, int y) {
    visited[x][y] = 1; // 현재 위치 방문 표시
    int count = 1; // 현재 집 포함

    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; // 다음 행
        int ny = y + dy[i]; // 다음 열

        // 유효 범위 안에 있고, 방문하지 않았으며, 집이 있을 경우
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && map[nx][ny] == 1) {
                count += dfs(nx, ny); // 재귀적으로 연결된 집 탐색
            }
        }
    }

    return count; // 연결된 집의 총 개수 반환
}

// ------------------------------
// 메인 함수: 입력, DFS 수행, 결과 정렬 및 출력
// ------------------------------
int main() {
    scanf("%d", &n); // 지도 크기 입력

    // 지도 정보 입력 처리
    for (int i = 0; i < n; i++) {
        char line[MAX_SIZE + 1]; // 한 줄 입력을 위한 문자열
        scanf("%s", line);
        for (int j = 0; j < n; j++) {
            map[i][j] = line[j] - '0'; // 문자 → 정수 변환 ('1' → 1, '0' → 0)
            visited[i][j] = 0; // 방문 배열 초기화
        }
    }

    // 전체 지도를 순회하면서 단지를 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                int size = dfs(i, j); // 새로운 단지 발견 시 DFS 수행
                complex_sizes[complex_count++] = size; // 단지 크기 저장
            }
        }
    }

    // 단지 크기들을 오름차순으로 정렬 (삽입 정렬 방식)
    for (int i = 0; i < complex_count - 1; i++) {
        for (int j = i + 1; j < complex_count; j++) {
            if (complex_sizes[i] > complex_sizes[j]) {
                int temp = complex_sizes[i];
                complex_sizes[i] = complex_sizes[j];
                complex_sizes[j] = temp;
            }
        }
    }

    // 결과 출력
    printf("%d\n", complex_count); // 총 단지 수 출력
    for (int i = 0; i < complex_count; i++) {
        printf("%d\n", complex_sizes[i]); // 각 단지 크기 출력 (오름차순)
    }

    return 0;
}
