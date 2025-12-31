#include <iostream>
#include <algorithm>

using namespace std;
int N, arr[1001], dp[1001], dp2[1001], maxV;
int main() {
    for (int i = 0; i < 1001; i++) {
        dp[i] = 1;
        dp2[i] = 1;
    }

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        maxV = max(maxV, arr[i]);
    }

    // 감소하는 부분
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // 증가하는 부분
    for (int i = N; i >= 1; i--) {
        for (int j = N; j > i; j--) {
            if (arr[j] > arr[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, dp[i] + dp2[i] - 1);
    }

    if (result == 1)
        cout << 1 << "\n";
    else
        cout << result << "\n";

    return 0;
}
