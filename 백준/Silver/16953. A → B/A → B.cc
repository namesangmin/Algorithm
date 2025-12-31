#include <iostream>

using namespace std;
int N, M, temp=1;
int result;
bool Get(int n) {
	//cout << n << "\n";
	//cout << "temp : " << temp << "\n";
	if (n < N) return false;
	if (n == N) {
		result = temp;
		return true;
	}
	temp++;
	if (n % 2 == 0) {
		if(Get(n / 2))
			return true;
	}
	else if(n % 10 == 1){	
		if(Get((n - 1) / 10))
			return true;
	}
	temp--;
	return false;
}
int main() {
	cin >> N >> M;
	//cout << "result : " << result << "\n";
	if (Get(M)) {
		cout << result << "\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}