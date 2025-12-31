#include <iostream>
using namespace std;

int R, C, ans;
char arr[21][21];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool m[26]; 

void input() {
    cin >> R >> C;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> arr[r][c];
        }
    }
    for (int i = 0; i < 26; i++) {
        m[i] = false;
    }
}

void func(int r, int c, int cnt) {
    char c_ch = arr[r][c];
    int idx = c_ch - 'A';
    m[idx] = true;
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int nc = c + dx[i];
        int nr = r + dy[i];
        if (nc >= 1 && nc <= C && nr >= 1 && nr <= R) {
            char n_ch = arr[nr][nc];
            int n_idx = n_ch - 'A';
            if (!m[n_idx]) {
                func(nr, nc, cnt + 1);
            }
        }
    }
    m[idx] = false; 
}

int main() {
    input();
    func(1, 1, 1);
    cout << ans << "\n";
    return 0;
}
