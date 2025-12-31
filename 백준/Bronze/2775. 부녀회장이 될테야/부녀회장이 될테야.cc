#include <iostream>
using namespace std;

int dp[15][15]; 

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= 14; i++) {
        dp[0][i] = i;
    }

    for (int i = 0; i < T; i++) {
        int n, th;
        cin >> n >> th;

        for (int i = 1; i <= n; i++) { // 층
            for (int j = 1; j <= th; j++) { // 호수
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        cout << dp[n][th] << "\n"; 
    }

    return 0;
}
