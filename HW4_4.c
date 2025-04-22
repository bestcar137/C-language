#include <stdio.h>

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element data[10000];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

void push(StackType *s, element item) {
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    return s->data[(s->top)--];
}

int n;
char maze[100][100];

void push_loc(StackType *s, int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n) return;
    if (maze[r][c] == '0' || maze[r][c] == 'x') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

int main(void) {
    StackType s;
    element here, entry;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", maze[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (maze[i][j] == 'e') {
                entry.r = i;
                entry.c = j;
            }

    init_stack(&s);
    here = entry;

    while (maze[here.r][here.c] != 'x') {
        int r = here.r;
        int c = here.c;

        if (maze[r][c] != 'e') maze[r][c] = '.';

        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);

        if (is_empty(&s)) {
            printf("fail\n");
            return 0;
        } else {
            here = pop(&s);
        }
    }

    printf("success\n");
    return 0;
}
