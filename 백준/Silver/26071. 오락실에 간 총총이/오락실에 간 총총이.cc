#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, ans;
vector<pair<int, int>> gom;
void input() {
    cin >> N;
    char tm;
    int L = 0, R = 110101010, U = 0, D = 101010101;
    int x = 0, y = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> tm;
            if (tm == 'G') {
                U = max(U, r);
                D = min(D, r);
                L = max(L, c);
                R = min(R, c);
            }
        }
    }
    if (L == R && U == D) {
        x = 0; y = 0;
    }
    else if (U == D) {
        x = min(L, (N - 1) - R);
    }
    else if (L == R) {
        y = min(U, (N - 1) - D);
    }
    else {
        x = min(L, (N - 1) - R);
        y = min(U, (N - 1) - D);
    }
    ans = x + y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout <<ans<< "\n";
    return 0;
}