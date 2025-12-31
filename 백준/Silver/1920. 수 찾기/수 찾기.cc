#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    cin.tie(NULL);
    cin.tie(NULL);

	ios_base::sync_with_stdio(false);
	int n;
	int find_n;
	int arr[100001];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> find_n;
	int find_input;
	for (int i = 0; i < find_n; i++) {
		cin >> find_input;
		if (binary_search(arr, arr + n, find_input))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
	}
	return 0;
}