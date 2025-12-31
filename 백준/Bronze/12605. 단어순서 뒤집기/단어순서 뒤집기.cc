#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> vvs;                  
vector<vector<string>> vvsResult; 

void input() {
	cin >> N;
	cin.ignore();
	vvs.resize(N);
	vvsResult.resize(N);
	for (int i = 0; i < N; i++) {
		getline(cin, vvs[i]);
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		const string& line = vvs[i];
		int end = line.size();
		vector<string>& result = vvsResult[i];

		for (int j = line.size() - 1; j >= 0; j--) {
			if (line[j] == ' ') {
				int start = j + 1;
				result.push_back(line.substr(start, end - start));
				end = j;
			}
		}
        
		if (end > 0)
			result.push_back(line.substr(0, end));
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << "Case #" << i + 1 << ": ";
		const vector<string>& words = vvsResult[i];
		for (int j = 0; j < words.size(); j++) {
			cout << words[j];
			if (j != words.size() - 1) cout << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	print();
	return 0;
}
