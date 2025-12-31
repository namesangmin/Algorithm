#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;
int main() {
	deque<int> dq;
	int T, n;
	string func, str, temp;
	// 만약 숫자이면 데크에 담기
	// 아니면 continue;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> func >> n >> str;
		int count = 0;

		if (n == 0 && func.find('D') != string::npos) {
			cout << "error\n";
			continue;
		}
		// 파싱 처리
		for (char c : str) {
			if (isdigit(c)) {
				temp += c;
			}
			else if (!temp.empty()) {
				int input_number = stoi(temp);
				dq.push_back(input_number);
				temp.clear();
			}
		}

		// 함수 기능을 하나씩 처리함
		bool isR = false;
		bool check = false;
		for (int i = 0; i < func.length(); i++) {
			if (dq.empty() && func[i] == 'D') {
				cout << "error\n";
				check = true;
				break;
			}

			if (func[i] == 'R')
				isR = !isR;

			if (isR) {
				if (func[i] == 'D')
					dq.pop_back();
			}
			else {
				if (func[i] == 'D')
					dq.pop_front();
			}
		}
		// 출력
		if (!check) {
			cout << "[";
			if (isR) {
				for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
					cout << *it;
					if (it + 1 != dq.rend()) {
						cout << ",";
					}
				}
			}
			else {
				for (auto it = dq.begin(); it != dq.end(); ++it) {
					cout << *it;
					if (it + 1 != dq.end()) {
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
		dq.clear();
	}
	return 0;
}