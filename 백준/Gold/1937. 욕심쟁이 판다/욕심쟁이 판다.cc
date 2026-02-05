#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct state {
    int val;
    int r;
    int c;
};

// 정렬을 위한 비교 함수 (내림차순: 값이 큰 순서대로)
bool cmp(const state& s1, const state& s2) {
    return s1.val > s2.val; 
}

int N;
int Graph[505][505];
int memo[505][505];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<state> v;

void input() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> Graph[r][c];
            // 큐에 넣는 대신 벡터에 저장
            v.push_back({ Graph[r][c], r, c });
        }
    }
}

int func() {
    // 1. 값이 큰 순서대로 정렬 (N^2 log(N^2))
    sort(v.begin(), v.end(), cmp);

    int ans = 0;

    // 2. 큰 값부터 하나씩 꺼내서 확인
    for (const auto& s : v) {
        int r = s.r;
        int c = s.c;
        int cMax = 1;

        for (int i = 0; i < 4; i++) {
            int nx = c + dx[i];
            int ny = r + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (Graph[ny][nx] > Graph[r][c]) {
                cMax = max(cMax, memo[ny][nx] + 1);
            }
        }
        
        memo[r][c] = cMax;
        ans = max(ans, cMax);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << func() << "\n";
    return 0;
}