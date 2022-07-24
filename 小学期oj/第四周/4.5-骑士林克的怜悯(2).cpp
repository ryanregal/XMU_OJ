#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 155;

int n, m;
char g[N][N];
int dist[N][N];

int bfs(PII start, PII end)
{
    queue<PII> q;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y] = 0;

    q.push(start);

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (g[x][y] == '*') continue;
            if (dist[x][y] != -1) continue;
            dist[x][y] = dist[t.x][t.y] + 1;

            if (make_pair(x, y) == end) return dist[x][y];

            q.push({x, y});
        }
    }

    return -1;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    PII start, end;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == 'K') start = {i, j};
            else if (g[i][j] == 'H') end = {i, j};

    cout << bfs(start, end) << endl;

    return 0;
}
