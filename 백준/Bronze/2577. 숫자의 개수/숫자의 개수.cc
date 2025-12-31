#include <iostream>
#include <string>
using namespace std;
int main() {
	int input;
	int result = 1;
	int output[10] = { 0 };
	for (int i = 0; i < 3; i++) {
		cin >> input;
		result *= input;
	}
	string str = to_string(result);
	for (int i = 0; i < str.length(); i++) {
		int index = str[i] - '0';
		output[index]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << output[i] << endl;
	}
	return 0;
}