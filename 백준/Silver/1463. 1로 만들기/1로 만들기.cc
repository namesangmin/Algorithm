#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x;

	cin >> x;
	// i = 1 일 때, 0.. 그냥 break;와 같음.
	for (int i = 2; i <= x; i++) {
		
		arr[i] = arr[i - 1] + 1;
		
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}

		if(i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}

	}
	
	cout << arr[x] << "\n";
	return 0;
}