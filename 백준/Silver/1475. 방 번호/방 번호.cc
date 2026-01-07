#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> num(10, 0);
	char tmCh;
	while (true) {
		tmCh = cin.get();

		if (tmCh == '\n') break;
		num[tmCh - '0']++;
	}
	num[6] += num[9];
	num[9] = 0;
    num[6] = (num[6] + 1) / 2;
    int maxVal = *max_element(num.begin(), num.end());
    cout << maxVal << "\n";
	return 0;
}