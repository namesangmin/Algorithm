#include <iostream>
#include <string>

using namespace std;
int main() {
	int input;
	string OX;
	cin >> input;
	for (int i = 0; i < input; i++) {
		int cnt = 1;
		int score = 0;
		cin >> OX;
		for (int i = 0; i < OX.length(); i++) {
			if (OX[i] == 'O') {
				score += cnt;
				cnt++;
			}
			else {
				cnt = 1;
			}
		}
		cout << score << endl;
	}
	return 0;
}