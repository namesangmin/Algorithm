#include <iostream>
#define MOD_NUMBER 42

using namespace std;

int main() {
	int input;
	int cnt[42] = {0};
	int result = 0;
	for (int i = 0; i < 10; i++) {
		cin >> input;
		int temp = input % MOD_NUMBER;
		cnt[temp] = 1;	
	}

	for (int i = 0; i < MOD_NUMBER; i++) {
		if (cnt[i] != 0)
			result++;

	}
	cout << result << endl;
	return 0;
}