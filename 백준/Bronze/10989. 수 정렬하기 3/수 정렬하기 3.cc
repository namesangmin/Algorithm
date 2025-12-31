#include <iostream>
#define MAX 10001
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input;
	int arr[MAX] = { 0 };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[input]++;
	}
	for (int i = 0; i < MAX; i++) {
		/*while (arr[i]) {
			cout << i << "\n";
			arr[i]--;
		}*/
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
		/*if (arr[i] != 0) {					x
			// cout << "arr" << i << " : " << arr[i] << endl;
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}*/
	}
	return 0;
}