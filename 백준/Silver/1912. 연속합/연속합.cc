#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int dp[100001]; 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // 기저 상태
    dp[1] = arr[1];
    int ans = dp[1];

    for (int i = 2; i <= N; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}