#include <stdio.h>

#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT];

char read_pixel(int x, int y)
{
    return screen[y][x];
}

void write_pixel(int x, int y, int color)
{
    screen[y][x] = color;
}

//  사용자가 구현해야 하는 함수
void flood_fill(int x, int y)
{
    // 여기에 flood_fill 알고리즘 구현
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    if (read_pixel(x, y) != WHITE)
        return;
    write_pixel(x, y, BLACK);
    flood_fill(x - 1, y);
    flood_fill(x + 1, y);
    flood_fill(x, y - 1);
    flood_fill(x, y + 1);

    screen[y][x];
}

int main()
{
    int x, y; // 시작 좌표

    // 스크린 값 입력
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            scanf("%d", &screen[y][x]);
        }
    }
    // 시작 좌표 입력
    scanf("%d %d", &x, &y);

    // flood_fill 알고리즘 적용
    flood_fill(x, y);

    // 결과 출력
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == WIDTH - 1)
                printf("%d", screen[y][x]);
            else
                printf("%d ", screen[y][x]);
        }
        printf("\n");
    }

    return 0;
}
