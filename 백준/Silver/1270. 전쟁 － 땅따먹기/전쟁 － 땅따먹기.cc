#include <iostream>
#include <unordered_map>
using namespace std;

int N;

void func(unordered_map<long long, int>& m, int l) {
    for (auto& soldier : m) {
        if (soldier.second > l / 2) {
            cout << soldier.first << "\n";
            return;
        }
    }
    cout << "SYJKGW\n";
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int landScope;
        cin >> landScope;
        unordered_map<long long, int> m;
        m.reserve(landScope);  // 💡 메모리 미리 확보하면 성능 향상
        for (int l = 0; l < landScope; l++) {
            long long e;
            cin >> e;
            m[e]++;
        }
        func(m, landScope);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    return 0;
}
