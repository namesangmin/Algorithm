#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main() {
    int N;
    int dp[1001];

    for (int i = 0; i < 1001; i++) {
        dp[i] = 1;
    }
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {  
            if (arr[j] < arr[i]) {  
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, dp[i]);
    }
    cout << result << "\n";

    return 0;
}
