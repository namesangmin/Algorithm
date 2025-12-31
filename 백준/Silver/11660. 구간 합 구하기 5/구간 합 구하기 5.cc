#include <iostream>
using namespace std;

int arr[1025][1025];
int main() {
    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, M;
	int Sx, Sy, Ex, Ey;
	int input;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			arr[i][j] = input + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> Sx >> Sy >> Ex >> Ey;
		//cout << arr[Ex][Ey] << "\n";
		int result = arr[Ex][Ey] - arr[Sx - 1][Ey] - arr[Ex][Sy - 1] + arr[Sx - 1][Sy - 1];
		cout << result << "\n";
	}
	return 0;
}