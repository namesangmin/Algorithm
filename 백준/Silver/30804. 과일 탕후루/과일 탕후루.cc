#include <iostream>
using namespace std;

int arr[200001];
int Count[10]; 

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int front = 1, back = 0;
    int result = 0;
    int kind = 0;  

    while (back < n) {
        back++;
        if (Count[arr[back]] == 0) kind++;
        Count[arr[back]]++;

        while (kind > 2) {
            Count[arr[front]]--;
            if (Count[arr[front]] == 0) kind--;
            front++;
        }

        result = max(result, back - front + 1);
    }

    cout << result << "\n";
    return 0;
}
