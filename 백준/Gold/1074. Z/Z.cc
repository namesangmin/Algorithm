#include <iostream>

using namespace std;
int N, r, c;
int Count;

void f(int x, int y, int size) {
    //cout << "x : " << x << " y : " << y << " size : " << size <<" count : " << Count << "\n";
    if (x == c && y == r) {
        cout << Count << "\n";
        return;
    }
    if ((x <= c && y <= r) && (c < x + size && r < y + size)) {
        // 1 사분면
        f(x, y, size / 2);
        // 2 사분면
        f(x + size / 2, y, size / 2);
        // 3 사분면
        f(x, y + size / 2, size / 2);
        // 4 사분면
        f(x + size / 2, y + size / 2, size / 2);
    }
    else
        Count += size * size;
}
int main() {
    cin >> N >> r >> c;
    int size = 1 << N;
    f(0, 0, size);
    return 0;
}
