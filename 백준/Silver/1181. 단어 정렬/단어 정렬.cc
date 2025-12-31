#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b) {  

	if( a.size() == b.size()){
		return a < b;
	}
	return a.size() < b.size(); 
}

int main() {
	int N;
	string input;
	vector<string>v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	// 중복 방지

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v.begin(), v.end(),compare);


	for (const auto & a : v) {
		cout << a << "\n";
	}

	return 0;
}