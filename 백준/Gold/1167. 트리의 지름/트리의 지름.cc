#include <iostream>
#include <vector>
#include <algorithm>
// for문으로 start node를 찾으려면 시간복잡도가 o(n^2)이라 최대 100억임
// for문으로 찾으면 안됨. 
// 그래서 visited 배열을 하나 둬서 시간복잡도를 줄여야 함.
// 시작을 1로 잡고 돌려

using namespace std;
int N;
vector<vector<pair<int, int>>> v_pp;
bool visited[100001];
int max_value, f_node;
void dfs(int node, int c_value) {
    // 넘겨줘얄 인자들
    // 1. 다음 노드, 가중치
    // DFS로 최하 노드까지가고 더함. 1부터 시작, 각 노드에는 최대 값이 들어 있음.
    visited[node] = true;
    if (max_value < c_value)
    {
        max_value = c_value;
        f_node = node;
    }

    //cout << "current node : " << node << "\n";
    for (int i = 0; i < v_pp[node].size(); i++) {
        int n_node = v_pp[node][i].first;
        int n_value = v_pp[node][i].second;
       // cout << "n_node : " << n_node << " value : " << n_value << "\n";
        if (!visited[n_node]) {
           // cout << "max_value : " << max_value << "\n";
            dfs(n_node, n_value + c_value);
        }
    }
}

int main() {
    cin >> N;
    //  1부터 시작하므로 N + 1
    v_pp.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int start_node;
        cin >> start_node;
        while (true) {
            int end_node, value;
            cin >> end_node;
            if (end_node == -1)
                break;
            cin >> value;
            v_pp[start_node].push_back({ end_node, value });
        }
    }
    // 디벅
    /*
    for (int i = 1; i <= N; i++) {
        cout << "Node " << i << ": ";
        for (auto edge : v_pp[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << "\n";
    }
    */
    dfs(1,0);
    // 두 번째 DFS
    fill(visited, visited + N + 1, false);
    max_value = 0;
    dfs(f_node,0);
    cout << max_value << "\n";
    return 0;
}
