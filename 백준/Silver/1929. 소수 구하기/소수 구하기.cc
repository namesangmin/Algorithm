#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int N, M;
	int count = 0;
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		if (i == 1)continue;
		if (i == 2 || i == 3) {
			cout << i << "\n";
			continue;
		}
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) break; 
			if (int(sqrt(i)) == j) cout << i << "\n";
		}
	}
	return 0;
}