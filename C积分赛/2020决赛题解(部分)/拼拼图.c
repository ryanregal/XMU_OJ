#include <stdbool.h>
#include <stdio.h>
typedef struct
{
    int x, y;
} Point;
void r90c(Point *p) // 顺时针旋转90度
{
    int x = p->x, y = p->y;
    p->x = y;
    p->y = -x;
}
void r90a(Point *p) // 逆时针旋转90度
{
    int x = p->x, y = p->y;
    p->x = -y;
    p->y = x;
}
void r180(Point *p) // 旋转180度
{
    p->x = -p->x;
    p->y = -p->y;
}
void shift(Point *p, int dx, int dy) // 平移
{
    p->x += dx;
    p->y += dy;
}
bool less_than(Point p1, Point p2) // 比较两个点
{
    return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}
void swap(Point *p1, Point *p2) // 交换两个点
{
    Point t = *p1;
    *p1 = *p2;
    *p2 = t;
}
Point line[8][2505];
int main()
{
    int n, m, x, y, ok = false;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d%d", &line[i][j].x, &line[i][j].y);
    for (int i = 0; i < n; ++i)
        r90a(&line[0][i]), shift(&line[0][i], m, 0);
    for (int i = 0; i < n; ++i)
        r180(&line[1][i]), shift(&line[1][i], m, m);
    for (int i = 0; i < n; ++i)
        r90c(&line[2][i]), shift(&line[2][i], 0, m);
    for (int i = 0; i < n; ++i)
        r90c(&line[4][i]);
    for (int i = 0; i < n; ++i)
        shift(&line[5][i], 0, -m);
    for (int i = 0; i < n; ++i)
        r90a(&line[6][i]), shift(&line[6][i], m, -m);
    for (int i = 0; i < n; ++i)
        r180(&line[7][i]), shift(&line[7][i], m, 0);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < n; ++j) // 排下序
            for (int k = 0; k < n - 1; ++k)
                if (less_than(line[i][k], line[i][k + 1]))
                    swap(&line[i][k], &line[i][k + 1]);
    for (int i = 0; i < 4; ++i)
        for (int j = 4; j < 8; ++j)
        {
            bool is_equal = true;
            for (int k = 0; k < n; ++k)
                if (line[i][k].x != line[j][k].x || line[i][k].y != line[j][k].y)
                    is_equal = false;
            if (is_equal)
                ok = true;
        }
    puts(ok ? "YES" : "NO");
    return 0;
}
