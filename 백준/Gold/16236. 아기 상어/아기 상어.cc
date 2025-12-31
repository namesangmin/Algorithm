#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
#define INT_MAX 210000000
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m, siz = 2, cnt = 0, ans = 0;
pair<int, int> cur_pos;
int board[22][22];

void eat()
{
    if (++cnt == siz)
    {
        siz++;
        cnt = 0;
    }
}

int bfs()
{
    queue<pair<int, int>> Q;
    Q.push(cur_pos);

    int dist[21][21] = {};
    dist[cur_pos.X][cur_pos.Y] = 1;

    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] > siz) continue;
            if (dist[nx][ny] > 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx,ny });
        }
    }

    int len = INT_MAX;
    pair<int, int> tar_pos = { -1,-1 };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] > 0 && board[i][j] != 0 && board[i][j] < siz && len > dist[i][j] - 1)
            {
                len = dist[i][j] - 1;
                tar_pos = { i,j };
            }
        }
    }

    if (len == INT_MAX) return 0;

    cur_pos = tar_pos;
    return len;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9) cur_pos = { i,j };
        }
    }

    while (1)
    {
        board[cur_pos.X][cur_pos.Y] = 0;
        int tmp = bfs();
        if (tmp == 0) break;

        ans += tmp;
        eat();
    }

    cout << ans;
}