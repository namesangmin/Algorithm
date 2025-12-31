#include <iostream>
#include <queue>
using namespace std;

int N, white = 0, blue = 0;
bool paper[129][129];
queue<pair<pair<int, int>, int>> q_pp;

// 검사
bool check(int x, int y, int size) {
    bool color = paper[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color)
                return false;
        }
    }
    return true;
}

void bfs(int x, int y, int size) {
    q_pp.push({ {x, y}, size });
     
    while (!q_pp.empty()) {
        int c_x = q_pp.front().first.first;
        int c_y = q_pp.front().first.second;
        int c_size = q_pp.front().second;
        q_pp.pop();

        // 다 같은 색?
        if (check(c_x, c_y, c_size)) {
            if (!paper[c_x][c_y])
                white++;
            else
                blue++;
        }
        else {
            // (0,0)기준
            // 같은 색이 아니면?
            int div_size = c_size / 2;
            // 1사분면
            q_pp.push({ {c_x, c_y}, div_size });
            // 2사분면
            q_pp.push({ {c_x + div_size, c_y}, div_size });
            // 3사분면
            q_pp.push({ {c_x + div_size, c_y + div_size}, div_size });
            // 4사분면
            q_pp.push({ {c_x, c_y + div_size}, div_size });
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    bfs(0, 0, N);
    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}
