#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int N;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
       // if (arr[i] == 1)
        //    dp[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i],dp[j]+arr[i]);
               // cout << "i : " << i << " | " << "dp : " << dp[i] << " arr : " << arr[j] << "\n";
            }
        }
    }
 //  cout << "\n";
    int result = 0;
    for (int i = 1; i <= N; i++) {
   //   cout << dp[i] << "\n";
        result = max(result, dp[i]);
    }
    cout << result << "\n";

    return 0;
}
