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

        // 🔥 불 먼저 확산
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
                        q_fire.push({ n_x, n_y, Count + 1 });
                    }
                }
            }
        }

        // 🚶‍♂️ 사람 이동
        int person_size = q_p.size();
        for (int i = 0; i < person_size; i++) {
            int c_x = q_p.front().x;
            int c_y = q_p.front().y;
            int Count = q_p.front().Count;
            q_p.pop();

            // 사람이 건물 밖(가장자리)에 도달하면 탈출 성공
            if (c_x == 1 || c_x == endX || c_y == 1 || c_y == endY) {
                return Count;
            }

            for (int j = 0; j < 4; j++) {
                int n_x = c_x + dx[j];
                int n_y = c_y + dy[j];

                if (n_x > 0 && n_x <= endX && n_y > 0 && n_y <= endY) {
                    // 🚫 사람이 이동할 곳이 '#' (벽) 이거나 '*' (불) 이면 이동 불가
                    if (!visited[n_y][n_x] && arr[n_y][n_x] == '.') {
                        visited[n_y][n_x] = true;
                        q_p.push({ n_x, n_y, Count + 1 });
                    }
                }
            }
        }
    }
    return -1; // 탈출 실패
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
                } else if (arr[h][w] == '*') {
                    q_fire.push({ w, h, 1 });
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
