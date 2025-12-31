#include <iostream>
#include <cstring>
using namespace std;
string str;
char arr[101];
int main() {
	//getline(cin, str);
	cin.getline(arr, 101);
	for (int i = 0; i < strlen(arr); i++) {
		cout << arr[i];
		if ((i + 1) % 10 == 0)
			cout << "\n";
		//if (i + 1 % 10 == 0)
		//	cout << "\n";
	}
	return 0;
}