#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 9999999
using namespace std;

int N;
int arr[126][126];
//int result[126][126];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int sX, int sY) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    int result[126][126] = { INF, };
    memset(result, INF, sizeof(result));

    pq.push({ arr[sY][sX],{sX, sY} });
    result[sY][sX] = arr[sY][sX];

    while (!pq.empty()) {
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int c_cost = pq.top().first;
        pq.pop();

        if (c_cost > result[cy][cx]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                int n_cost = c_cost + arr[ny][nx];

                if (n_cost < result[ny][nx]) {
                    result[ny][nx] = n_cost;
                    pq.push({ n_cost,{nx, ny} });
                }
            }
        }
    }
    return result[N][N];
}

void input() {
    int tc = 1;
    while (true) {
        cin >> N;
        if (N == 0) return; 

        memset(arr, 0, sizeof(arr));

        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                cin >> arr[j][k];
            }
        }
        cout << "Problem " << tc++ << ": " << bfs(1, 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}
