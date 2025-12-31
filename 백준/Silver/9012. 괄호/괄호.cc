#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string T;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T;
		int	check = -1;
		for (int j = 0; j < T.length(); j++) {
			if (T[j] == '(')
				check++;
			else
				check--;
			if (check == -2) 
				break;
		}
		if (check == -1)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}