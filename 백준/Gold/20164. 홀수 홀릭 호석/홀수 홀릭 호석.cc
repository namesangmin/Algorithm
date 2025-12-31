#include <iostream>
#include <string>
#include <vector>
using namespace std;
string input;
int Max = 0, Min = 999;
int Count(string s) {
	int C= 0;
	for (int i = 0; i < s.size(); i++) {
		int check = (s[i] - '0') % 2;
		if (check == 1)
			C++;
	}
	return C;
}

void func(string s, int total) {
	int rule = s.size();
	int sumNum = 0;
	total += Count(s);
	if (rule == 1) {
		if (total < Min)Min = total;
		if (total > Max)Max = total;
		return;
	}
	else if (rule == 2) {
		for (int i = 0; i < s.size(); i++) {
			sumNum += s[i] - '0';
		}
		string Next = to_string(sumNum);
		func(Next, total);
	}
	else if (rule >= 3) {
		for (int i = 1; i < s.size() - 1; ++i) {
			for (int j = i + 1; j < s.size(); ++j) {
				string a = s.substr(0, i);
				string b = s.substr(i, j - i);
				string c = s.substr(j);
				sumNum = stoi(a) + stoi(b) + stoi(c);
				string Next = to_string(sumNum);
				func(Next, total);
			}
		}
	}
}
int main() {
	cin >> input;
	func(input,0);
	cout << Min << " " << Max;
	return 0;
}