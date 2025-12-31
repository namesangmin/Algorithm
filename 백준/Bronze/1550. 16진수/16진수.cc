#include <iostream>
#include <string>
using namespace std;
int main() {
    string hex_number;
    cin >> hex_number;
    int decimal_number = stoi(hex_number, nullptr, 16);

    cout << decimal_number << endl;
    return 0;
}
