#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct info {
    int y, x, dir;
    int orderCnt;
};
// 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4
int lookX[5] = { 0,1,-1,0,0 };
int lookY[5] = { 0,0,0,1,-1 };

// 1을 넣었을 때 왼쪽(4), 2를 넣었을 때 왼쪽(3) ...
int L[5] = { 0,4,3,1,2 };
// 1을 넣었을 때 오른쪽(3), 2를 넣었을 때 오른쪽(4) ...
int R[5] = { 0,3,4,2,1 };
// Go k - k 는 1 또는 2 또는 3일 수 있다. 현재 향하고 있는 방향으로 k 칸만큼 움직인다. 
int Go[3] = { 1,2,3 };
vector<vector<int>> arr;
vector<vector<vector<bool>>> visited;
vector<info> stPoint, endPoint;
int M, N;
void input() {
    cin >> M >> N;
    arr.resize(M + 1, vector<int>(N + 1, 0));
    visited.resize(M + 1, vector<vector<bool>>(N + 1, vector<bool>(5, false)));

    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> arr[r][c];
        }
    }
    int r, c, dir;
    cin >> r >> c >> dir;
    stPoint.push_back({ r,c,dir,0 });
    cin >> r >> c >> dir;
    endPoint.push_back({ r,c,dir,0 });
}

int func() {
    int ans = 100000000;
    queue<info> q;
    q.push({ stPoint.front().y,stPoint.front().x,stPoint.front().dir,0 });
    visited[stPoint.front().y][stPoint.front().x][stPoint.front().dir] = true;

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cDir = q.front().dir;
        int cOrderCnt = q.front().orderCnt;
        q.pop();

        if (cx == endPoint.front().x && cy == endPoint.front().y && cDir == endPoint.front().dir) {
            ans = min(ans, cOrderCnt);
        }

        // 1. 방향 그대로 직진
        for (int g = 0; g < 3; g++) {
            // 가는 거리
            int nx = cx + lookX[cDir] * Go[g];
            int ny = cy + lookY[cDir] * Go[g];
            // 다음 위치에 벽이 있는 경우 바로 나옴
            if (nx < 1 || nx > N || ny < 1 || ny > M) break;
            if (arr[ny][nx] == 1) break;
            // 직진 1, 2, 3 다 같음
            if (!visited[ny][nx][cDir]) {
                q.push({ ny,nx,cDir, cOrderCnt + 1 });
                visited[ny][nx][cDir] = true;
            }
        }

        // 2. 방향 바꾸기
        int nL_dir = L[cDir];
        int nR_dir = R[cDir];
        if (!visited[cy][cx][nL_dir]) {
            visited[cy][cx][nL_dir] = true;
            q.push({ cy,cx,nL_dir,cOrderCnt + 1 });
        }
        if (!visited[cy][cx][nR_dir]) {
            visited[cy][cx][nR_dir] = true;
            q.push({ cy,cx,nR_dir,cOrderCnt + 1 });
        }
    }
    return ans;
}
int main() {
    input();
    cout << func() << "\n";
    return 0;
}