#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(const char* arr) {
    int len = strlen(arr);
    for (int i = 0; i < len / 2; ++i) {
        if (arr[i] != arr[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    while (true) {
        char arr[6];  // 5자리 수와 null terminator를 고려하여 크기를 6으로 설정
        cin >> arr;

        if (arr[0] == '0') {
            break;
        }

        if (isPalindrome(arr)) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
    return 0;
}
