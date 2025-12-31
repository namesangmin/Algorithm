#include <iostream>
using namespace std;
int arr[20000003];
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	int N;
	int input;
	int find_input;
	int find_num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		if (input < 0) { // 1~10000001
			arr[-input] += 1;
		}
		else {// 10000002~ 20000002
			arr[input+10000001] += 1;
		}
	}
	cin >> find_input;
	for (int i = 1; i <= find_input; i++) {
		cin >> find_num;
		if (find_num < 0) {
			cout << arr[-find_num] << " ";
		}
		else {
			cout << arr[find_num+ 10000001] << " ";
		}
	}
	cout << "\n";
	return 0;
}