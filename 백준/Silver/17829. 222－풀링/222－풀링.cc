#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, arr[1025][1025];

int integre(int r, int c) {
    vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            v.push_back(arr[r + i][c + j]);
        }
    }
    sort(v.begin(), v.end());
    return v[2];
}

int func(int r, int c, int Size) {
    if (Size == 2) {
        return integre(r, c);
    }

    int s = Size / 2;
    vector<int> v;
    v.push_back(func(r, c, s));
    v.push_back(func(r + s, c, s));
    v.push_back(func(r, c + s, s));
    v.push_back(func(r + s, c + s, s));

    sort(v.begin(), v.end());
    return v[2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> arr[r][c];
        }
    }

    int ans = func(0, 0, N);
    cout << ans << "\n";
    return 0;
}
