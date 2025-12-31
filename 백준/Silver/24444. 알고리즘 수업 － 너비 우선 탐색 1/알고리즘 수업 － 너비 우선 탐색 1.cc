#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> vv;
vector<bool> visited;
vector<int> ans;
int N, M, R;

void input() {
    int u, v;
    cin >> N >> M >> R;

    vv.resize(N + 1);
    visited.resize(N + 1, false);
    ans.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(vv[i].begin(), vv[i].end());  
    }
}

void bfs() {
    int Count = 1;
    queue<int> q;

    visited[R] = true;
    q.push(R);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans[node] = Count++;

        for (int next : vv[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    input();
    bfs();

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
