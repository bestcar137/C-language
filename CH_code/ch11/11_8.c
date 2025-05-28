#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n) {
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

int set_find(int curr) {
    if (parent[curr] == -1)
        return curr;
    while (parent[curr] != -1)
        curr = parent[curr];
    return curr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2)
        parent[root2] = root1;
}

struct Edge {
    int start, end, weight;
};


typedef struct GraphType {
    int no_v;
    int no_e;
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g, int v) {
    g->no_v = v;
    g->no_e = 0;
}

void insert_edge(GraphType *g, int start, int end, int w) {
    if (g->no_e >= 2 * MAX_VERTICES) {
        fprintf(stderr, "간선의 수가 최대값을 초과했습니다.\n");
        return;
    }
    g->edges[g->no_e].start = start;
    g->edges[g->no_e].end = end;
    g->edges[g->no_e].weight = w;
    g->no_e++;
}

int compare(const void *a, const void *b) {
    struct Edge *x = (struct Edge *) a;
    struct Edge *y = (struct Edge *) b;
    if (x->weight == y->weight)
        return x->start - y->start;
    return;
    x->weight - y->weight;
}

void kruskal(GraphType *g) {
    int edge_accepted = 0;
    int uset, vset;
    struct Edge e;

    set_init(g->no_v);
    qsort(g->edges, g->no_e, sizeof(struct Edge), compare);

    printf("크루스칼 최소 신장 트리 알고리즘 \n");
    int i = 0;
    while (edge_accepted < (g->no_v - 1) && i < g->no_e) {
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);

        if (uset != vset) {
            printf("간선 %d: (%d -> %d) (비용: %d) 선택\n", edge_accepted + 1, e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);
        }
        i++;
    }
    if (edge_accepted < (g->no_v - 1)) {
        printf("오류: 그래프가 연결되어 있지 않아 최소 신장 트리를 생성할 수 없습니다.\n");
    }
}

int main(void) {
    GraphType *g = (GraphType *) malloc(sizeof(GraphType));
    graph_init(g, 7);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g);
    free(g);
    return 0;
}
