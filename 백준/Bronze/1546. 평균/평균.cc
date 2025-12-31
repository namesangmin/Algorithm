#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	float input;
	float result = 0;
	vector<float> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	float largest = v[0];
	float len = static_cast<float>(v.size());
	for (int i = 0; i < len; i++) {
		largest = max(largest, v[i]);
	}
	for (int i = 0; i < len; i++) {
		result += ((v[i] / largest) * 100);
	}
	result /= len;
	cout << result << endl;
	return 0;
}