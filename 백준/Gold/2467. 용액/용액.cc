#include <iostream>
#include <cmath>
#define MAX 100000 + 500
using namespace std;

int N, arr[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void func() {
	int frontP = 0;
	int backP = N - 1;
	long long int temp = 1e10;  // 충분히 큰 값
	int front_ans = 0, back_ans = N - 1;

	while (frontP < backP) {
		long long int check_num = arr[frontP] + arr[backP];

		if (abs(temp) > abs(check_num)) {
			temp = check_num;
			front_ans = frontP;
			back_ans = backP;
		}

		if (check_num < 0) frontP++;
		else backP--;
	}

	cout << arr[front_ans] << " " << arr[back_ans] << "\n";
}

int main() {
	input();
	func();
	return 0;
}
