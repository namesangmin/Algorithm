#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int N;
	cin >> N;
	int input = N;
	for (int i = N; ; i++) {
		if (N <= 7) {
			if (i <= 2) {
				cout << "2\n";
				break;
			}else if (i <= 3) {
				cout << "3\n";
				break;
			}
			else if(i<=5){
				cout << "5\n";
				break;
			}
			else {
				cout << "7\n";
				break;
			}
		}
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) break;
			if (int(sqrt(i)) == j) {
				// 팰린드롬 검사
				int original_num = i;
				int temp_num = 0;
				while (original_num > 0) {
					temp_num = temp_num * 10 + original_num % 10;
					original_num /= 10;
				}
					if (i == temp_num) {
						cout << i << "\n";
						// 맞으면 그만
						return 0;
					}
			}
		}
	}
	return 0;
}