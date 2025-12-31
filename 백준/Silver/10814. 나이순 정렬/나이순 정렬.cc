#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, string>>v_p;
int n,age;
string name;

bool cmp(const pair<int,string>& a, const pair<int,string>& b) {
	return a.first < b.first;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v_p.push_back({ age,name });
	}
	stable_sort(v_p.begin(), v_p.end(), cmp);
	//cout << "\n";
	for (auto a : v_p) {
		cout << a.first <<" "<< a.second << "\n";
	}
	return 0;
}