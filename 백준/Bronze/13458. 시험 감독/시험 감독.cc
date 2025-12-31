#include <iostream>

using namespace std;

int A[1000001];
int main() {
    int N, B, C;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;

    long long total = 0;
    for (int i = 0; i < N; i++) {
        int remain = A[i];

        total++;
        remain -= B;

        if (remain > 0) {
            total += (remain + C - 1) / C;
        }
    }

    cout << total << "\n";
    return 0;
}
