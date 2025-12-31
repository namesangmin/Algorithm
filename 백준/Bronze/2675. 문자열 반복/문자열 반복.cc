#include <iostream>
#include <string>

using namespace std;
int main() {
	int N;
	int re;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> re >> str;
		int count = 0;
		int str_length;

		str_length = str.length()*re;

		for (int j = 1; j <= str_length; j++) {
			cout << str[count];

			if (j%re==0) {
				count++;
			}
		}
		printf("\n");
	}
	return 0;
}