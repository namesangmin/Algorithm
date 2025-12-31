#include <iostream>
#include <string>
using namespace std;

int main() {
    int result = 0;
    int currentNumber = 0;
    bool check_minus = false;
    string input;

    cin >> input;
    for (int i = 0; i <= input.size(); ++i) {
        if (i < input.size() && input[i] >= '0' && input[i] <= '9') {
            currentNumber = currentNumber * 10 + (input[i] - '0');
        }
        else {
            if (check_minus) {
                result -= currentNumber;
            }
            else {
                result += currentNumber;
            }
            currentNumber = 0;
            if (i < input.size() && input[i] == '-') {
                check_minus = true;
            }
        }
    }
    cout << result << "\n";
    return 0;
}
