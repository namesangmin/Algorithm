#include <iostream>
#include <map>

using namespace std;

map<string, bool> m;
int N, cnt;

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "ENTER") {
			m.clear();
		}
		else {
			if (m.find(str) == m.end()) {
				m[str] = true;
				cnt++;
			}
		}
	}
}

int main() {
	input();
	cout << cnt << "\n";
	return 0;
}