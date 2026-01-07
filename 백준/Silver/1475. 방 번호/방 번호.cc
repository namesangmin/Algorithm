#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<char> v;
	vector<int> num(10, 0);
	char tmCh;
	while (true) {
		tmCh = cin.get();

		if (tmCh == '\n') break;
		num[tmCh - '0']++;
	}
	num[6] += num[9];
	num[9] = 0;
	if (num[6] >= 2) {
		if (num[6] % 2 == 1)num[6]++;
		num[6] /= 2;
	}
	sort(num.begin(), num.end());
	cout << num[9] << "\n";
	return 0;
}