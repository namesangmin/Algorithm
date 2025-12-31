#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { return a < b; }
int temp[1001];
int main() {
	int n;
	int input;
	vector<int> arr;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end(), compare);
	int a = 0;
	int result = 0;
	for (const auto i : arr) {
		result += i;
		a += result;
		//cout << i << "\n";
	}
	cout << a << "\n";




	return 0;
}