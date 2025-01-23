#include <iostream>
#include <vector>
#define INF 99999999

using namespace std;
int N, M;
vector<vector<pair<int, int>>> vv_p;
vector<int> Cost;
bool visited[1001];

int min_index() {
    int min_cost = INF;
    int min_idx = -1;

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && Cost[i] < min_cost) {
            min_cost = Cost[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void dkt(int start) {
    Cost[start] = 0;

    for (int i = 1; i <= N; i++) {
        int new_node = min_index();
        if (new_node == -1) break; 

        visited[new_node] = true;

        for (auto& n : vv_p[new_node]) {
            int n_city = n.first;
            int n_cost = n.second;

            if (!visited[n_city] && Cost[n_city] > Cost[new_node] + n_cost) {
                Cost[n_city] = Cost[new_node] + n_cost;
            }
        }
    }
}

int main() {
    int start, end, price;
    int des_start, des_end;
    cin >> N >> M;
    vv_p.resize(N + 1);
    Cost.assign(N + 1, INF);

    for (int i = 0; i < M; i++) {
        cin >> start >> end >> price;
        vv_p[start].push_back({ end, price });
    }
    cin >> des_start >> des_end;

    dkt(des_start);
    cout << Cost[des_end] << "\n";
    return 0;
}
