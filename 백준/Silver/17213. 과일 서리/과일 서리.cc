#include <iostream>

using namespace std;

int main() {
	int fruit_n;
	int fruit_value;
	int result=1;
	cin >> fruit_n >> fruit_value;
	fruit_n = fruit_n - 1;
	fruit_value = fruit_value - 1;
	long long value = 1; 
	long long div = 1;  
	for (int i = 0; i < fruit_n; i++) {
		value *= (fruit_value - i); // 분자
		div *= (i + 1);             // 분모
	}
	result = (long long)(value / div);
	cout << result << "\n";
	return 0;
}