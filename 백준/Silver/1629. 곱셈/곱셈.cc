#include <iostream>
using namespace std;

long long int N, M, K;

long long modular_pow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

int main() {
    cin >> N >> M >> K;
    long long Kmod = K % N;
    long long Kdiv = K / N;

    if (Kmod != 0)
        Kdiv += 1;

    long long Mmod = M % Kdiv;
    long long Mdiv = M / Kdiv;

    long long pow_result = modular_pow(N, Kdiv, K);
    long long a = modular_pow(pow_result, Mdiv, K);
    long long b = modular_pow(N, Mmod, K);

    cout << (a * b) % K << "\n";

    return 0;
}
