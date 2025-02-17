#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

char arr[1001][1001];
bool visited[1001][1001];

struct node {
    int x, y, Count;
};

int bfs(int endX, int endY, queue<node>& q_p, queue<node>& q_fire) {

    while (!q_p.empty()) {
        int fire_size = q_fire.size();

        for (int i = 0; i < fire_size; i++) {
            int c_x = q_fire.front().x;
            int c_y = q_fire.front().y;
            int Count = q_fire.front().Count;
            q_fire.pop();

            for (int j = 0; j < 4; j++) {
                int n_x = c_x + dx[j];
                int n_y = c_y + dy[j];

                if (n_x > 0 && n_x <= endX && n_y > 0 && n_y <= endY) {
                    if (arr[n_y][n_x] != '#' && arr[n_y][n_x] != '*') {
                        arr[n_y][n_x] = '*';
                        q_fire.push({ n_x, n_y, 0  });
                    }
                }
            }
        }
        int p_size = q_p.size();

        for (int i = 0; i < p_size; i++) {
            int c_x = q_p.front().x;
            int c_y = q_p.front().y;
            int Count = q_p.front().Count;
            q_p.pop();

            if (c_x == 1 || c_x == endX || c_y == 1 || c_y == endY) {
                return Count;
            }

            for (int j = 0; j < 4; j++) {
                int n_x = c_x + dx[j];
                int n_y = c_y + dy[j];

                if (n_x > 0 && n_x <= endX && n_y > 0 && n_y <= endY) {
                    if (!visited[n_y][n_x] && arr[n_y][n_x] =='.') {
                        visited[n_y][n_x] = true;
                        q_p.push({ n_x, n_y, Count + 1 });
                    }
                }
            }
        }
    }
    return -1;
}

void input() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        queue<node> q_p;
        queue<node> q_fire;
        int x, y;
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cin >> x >> y;

        for (int h = 1; h <= y; h++) {
            for (int w = 1; w <= x; w++) {
                cin >> arr[h][w];

                if (arr[h][w] == '@') {
                    q_p.push({ w, h, 1 });
                    visited[h][w] = true;
                }
                else if (arr[h][w] == '*') {
                    q_fire.push({ w, h, 0 });
                }
            }
        }

        int result = bfs(x, y, q_p, q_fire);

        if (result == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << result << "\n";
    }
}

int main() {
    input();
    return 0;
}
