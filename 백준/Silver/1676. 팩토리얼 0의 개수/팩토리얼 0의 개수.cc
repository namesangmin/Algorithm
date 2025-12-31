#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	long long int multi_result = 1;
	int count5=0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i % 5 == 0) {
			multi_result = i;
			for (;;) {
				if(multi_result/5 == 0) {
					break;
				}
				if (multi_result % 5 != 0)
					break;
				count5++;
				multi_result /= 5;
			}
		}
	}
	cout << count5 << "\n";
	return 0;
}