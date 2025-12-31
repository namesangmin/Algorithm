#include <iostream>
#include <algorithm>  // std::max
#include <cmath>      // std::pow

using namespace std;

int main() {
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        int max_value = max({ a, b, c });
        int side1, side2;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (max_value == a) {
            side1 = b;
            side2 = c;
        }
        else if (max_value == b) {
            side1 = a;
            side2 = c;
        }
        else {
            side1 = a;
            side2 = b;
        }

        // 피타고라스 정리 검사
        if (pow(max_value, 2) == pow(side1, 2) + pow(side2, 2)) {
            cout << "right" << "\n";
        }
        else {
            cout << "wrong" << "\n";
        }

    }
    
    return 0;
}
