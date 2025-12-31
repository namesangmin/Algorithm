#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int N;

void input_f() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		while (!v.empty()) {
			if (v.back() <= input)
				v.pop_back();
			else
				break;
		}
		v.push_back(input);
	}
	cout << v.size() << "\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	input_f();
	return 0;
}