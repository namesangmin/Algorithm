#include <iostream>
#include <limits>

using namespace std;

int main() {
    int input;
    int number;
    int min_num = numeric_limits<int>::max(); // 가장 큰 정수로 초기화
    int max_num = numeric_limits<int>::min(); // 가장 작은 정수로 초기화

    cin >> input;
    for (int i = 0; i < input; i++) {
        cin >> number;
        if (number < min_num)
            min_num = number;
        if (number > max_num)
            max_num = number;
    }
    cout << min_num << " " << max_num << endl;
    return 0;
}
