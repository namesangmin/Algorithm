#include <iostream>
using namespace std;
int main() {
	int input;
	int min = 0;
	int temp = 0;
	int mod;
	int div;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		temp = i;
		mod = i % 10;
		div = i / 10;
		while (mod !=0 || div !=0) {
			temp += mod;
			mod = div % 10;
			div = div / 10;
		}
		if (input == temp) { 
			min = i;
			break;
		}
	}
	printf("%d", min);
	return 0;
}