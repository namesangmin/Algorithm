#include <iostream>
#include <algorithm>
using namespace std;
int count0;
int count1;
int arr[41][2];

void f(int n) {
    //
    if (arr[n][0] > 0 || arr[n][1] >0) {    //왼쪽 조건은 n==0일때용, 우측 조건은 n==1일때 용. 
       // cout << "n " << n << " " << arr[n][0] << " 1 " << arr[n][1] << '\n';
        return;
    }
    if (arr[n - 1][0] == 0)f(n - 1);
    
    arr[n][0] = arr[n - 1][0] + arr[n - 2][0];
    arr[n][1] = arr[n - 1][1] + arr[n - 2][1];
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,a;
    cin >> N;
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][1] = 1;
    arr[1][0] = 0;
    f(40);
    for (int i = 0; i < N; i++) {
        count0 = 0;
        count1 = 0;
        cin >> a;
        printf("%d %d\n", arr[a][0], arr[a][1]);
    }
	return 0;
}