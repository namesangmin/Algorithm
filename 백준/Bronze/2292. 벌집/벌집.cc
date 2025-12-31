#include <iostream>

using namespace std;
int main() {
	int N;

	cin >> N;
	if (N == 1)
		cout << "1" << "\n";
	else {
		int i = 0;
		int count = 0;
		int temp = 1;
		while (N>temp) {
			temp += (6 * i);
			//cout << temp << "\n";
			count++;
			 
			
			i++;
		}
		cout << count << "\n";


	}


	return 0;
}