#include <iostream>
#include <string>

using namespace std;
int main() {
	char str[101];
	int n;	
	int result = 0;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++ ) {
		int temp = (str[i] - '0');
		result += temp;
	}
	cout << result << "\n";

	return 0;
}