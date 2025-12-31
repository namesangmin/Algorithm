#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int l;
	int arr[51];
	char ch[52];
	int M = 1234567891;
	unsigned long long int result = 0;
	unsigned long long int temp = 1;
	cin >> l;
	for (int i = 0; i <= l-1; i++) {
		cin >> ch[i];
		arr[i] = ((int)(ch[i] - 'a') + 1);

		result += arr[i] * temp % M ;
		temp *= 31;
		temp %= M;
		result %= M;
	}
	cout << result << "\n";
	//cout << M % 31 << "\n";
	return 0;
}