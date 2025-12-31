#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N,M;
vector<bool>S;
string ch_input;

void add() {
	S[M] = true;
}
void remove() {
	if (S[M])
		S[M] = false;
}

void check() {
	
	if (S[M]) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
}

void toggle() {
	if (S[M]) {
		S[M] = false;
	}
	else {
		S[M] = true;
	}
}

void all() {
	S.clear();
	S.resize(21);

	for (int i = 1; i <= 20; i++) {
		S[i] = true;
	}
}

void empty() {
	S.clear();
	S.resize(21);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	S.resize(21);
	for (int i = 0; i < N; i++) {
		cin >> ch_input; 
		if (ch_input == "add" || ch_input == "check" || ch_input == "remove" || ch_input == "toggle") {
			cin >> M;
		}
		if (ch_input == "add") {
			add();
		}
		else if (ch_input == "check") {
			check();
		}
		else if (ch_input == "remove") {
			remove();
		}
		else if (ch_input == "toggle") {
			toggle();
		}
		else if (ch_input == "all") {
			all();
		}
		else { // empty
			empty();
		}
	}
	return 0;
}