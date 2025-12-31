#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int school, road;
bool school_W_M[1001];
vector<pair<int, pair<int, int>>> v_p;
vector<pair<int, pair<int, int>>> result;
int parent[1001];

int f(int n) {
    if (parent[n] == n) return n;
    return parent[n] = f(parent[n]);
}

void u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x != y) parent[y] = x;
}

void k() {
    for (int i = 0; i < v_p.size(); i++) {
        int a = v_p[i].second.first;
        int b = v_p[i].second.second;
        int cost = v_p[i].first;

        if (f(a) == f(b)) continue; 
        if (school_W_M[a] == school_W_M[b]) continue;

        result.push_back(v_p[i]); 
        u(a, b); 

        if (result.size() == school - 1) break; 
    }

    if (result.size() != school - 1) {
        cout << -1 << "\n";
        return;
    }

    int total = 0;
    for (auto& e : result) {
        total += e.first;
    }
    cout << total << "\n";
}

int main() {
    cin >> school >> road;

    char input_school;
    int input_school1, input_school2, value;

    for (int i = 1; i <= school; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= school; i++) {
        cin >> input_school;
        if (input_school == 'W') {
            school_W_M[i] = true;
        }
    }

    for (int i = 0; i < road; i++) {
        cin >> input_school1 >> input_school2 >> value;
        v_p.push_back(make_pair(value, make_pair(input_school1, input_school2)));
    }
    sort(v_p.begin(), v_p.end());
    k();

    return 0;
}
