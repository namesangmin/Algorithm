#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

int main() {

	map<string, int>map1;
	int N, M;
	char name[21];
	int idx= 0;

	cin >> N>> M;

	for (int i = 0; i < N; i++) {
		cin >> name;
		if (map1.count(name) < 1)
			map1[name] = 1;
		   
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		auto it = map1.find(name);

		if (it != map1.end()) {
			map1[name] = 2;
			idx++;
		}
	}
	cout << idx << "\n";

	for (auto it = map1.begin(); it != map1.end(); ++it) {
		if (it->second == 2)
			cout << it->first << "\n";
	}
	return 0;
}