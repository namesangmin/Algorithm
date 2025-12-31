#include <iostream>
using namespace std;

int N, num[12];
int oper[4]; // + - * /
int ansMax = -1000000001, ansMin = 1000000001;

void dfs(int idx, int current) {
    if (idx == N) {
        ansMax = max(ansMax, current);
        ansMin = min(ansMin, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i]--;
            int next = current;
            if (i == 0) next += num[idx];
            else if (i == 1) next -= num[idx];
            else if (i == 2) next *= num[idx];
            else if (i == 3) next /= num[idx];

            dfs(idx + 1, next);
            oper[i]++;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];
    for (int i = 0; i < 4; i++) cin >> oper[i];

    dfs(1, num[0]);

    cout << ansMax << "\n" << ansMin << "\n";
    return 0;
}
