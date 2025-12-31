#include <iostream>
#include <string>

using namespace std;
int main() {
	string str;
	int cnt = 0;
	bool check_blank = true;

	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		
		if (str[i] != ' ') {
			if (check_blank == true) {
				cnt++;
			}
			check_blank = false;
		}
		else {
			check_blank = true;
		}
	}



	cout << cnt << endl;

	return 0;
}