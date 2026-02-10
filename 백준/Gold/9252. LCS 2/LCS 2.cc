#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string ch, ch2;
int dp[2][1001]; 
char path[1001][1001]; 

void input() {
    cin >> ch >> ch2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    int n = ch.size();
    int m = ch2.size();
    int idx = 0; 

    for (int i = 1; i <= n; i++) {
        idx ^= 1; 
        int prev = idx ^ 1;

        for (int j = 1; j <= m; j++) {
            if (ch[i - 1] == ch2[j - 1]) {
                dp[idx][j] = dp[prev][j - 1] + 1;
                path[i][j] = 1; 
            } 
            else {
                if (dp[prev][j] >= dp[idx][j - 1]) {
                    dp[idx][j] = dp[prev][j];
                    path[i][j] = 2;
                } else {
                    dp[idx][j] = dp[idx][j - 1];
                    path[i][j] = 3; 
                }
            }
        }
    }

    // 결과 출력
    cout << dp[idx][m] << "\n"; 
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (path[i][j] == 1) { // 대각선 (정답 문자)
            ans += ch[i - 1];
            i--; j--;
        } 
        else if (path[i][j] == 2) { // 위로 이동
            i--;
        } 
        else { // 왼쪽으로 이동
            j--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}