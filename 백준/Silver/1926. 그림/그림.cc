#include <iostream>
#include <queue>

using namespace std;

int N, M;
queue<pair<int, int>> q_p;
bool visited[501][501];
bool Map[501][501];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int max_paper = 0;
int paper_count = 0;

void bfs() {
    while (!q_p.empty()) {
        int c_x = q_p.front().first;
        int c_y = q_p.front().second;
        q_p.pop();

        int temp = 1;

        queue<pair<int, int>> q_p2;
        q_p2.push({ c_x, c_y });
        visited[c_x][c_y] = true;

        while (!q_p2.empty()) {
            int x = q_p2.front().first;
            int y = q_p2.front().second;
            q_p2.pop();

            for (int i = 0; i < 4; i++) {
                int n_x = x + dx[i];
                int n_y = y + dy[i];

                if (n_x >= 1 && n_x <= N && n_y >= 1 && n_y <= M && !visited[n_x][n_y] && Map[n_x][n_y]) {
                    visited[n_x][n_y] = true;
                    q_p2.push({ n_x, n_y });
                    temp++;
                }
            }
        }

        max_paper = max(max_paper, temp);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int input;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> input;
            Map[i][j] = input;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (Map[i][j] && !visited[i][j]) {
                q_p.push({ i, j });
                paper_count++; 
                bfs();         
            }
        }
    }

    cout << paper_count << "\n";
    cout << max_paper << "\n";

    return 0;
}
