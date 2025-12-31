#include <iostream>
#include <string>

using namespace std;
int main() {
	int space = 0;
	int small_ch = 0;
	int large_ch = 0;
	int int_num = 0;
	int total_count = 0;
	//char input[101];
	string input;

	while (getline(cin, input)) {

		//cout << input << "\n";
		
		for (int i = 0; i < input.size(); i++) {
			// space
			if (input[i] == ' ') {
				space++;
			}
			// number
			else if (input[i] >= 46 && input[i] <= 57) {
				int_num++;
			}
			// large
			else if (input[i] >= 65 && input[i] <= 90) {
				large_ch++;
			}
			// small
			else if (input[i] >= 97 && input[i] <= 122) {
				small_ch ++;
			}
		}
		total_count = space + int_num + large_ch + small_ch;
		cout << small_ch << " " << large_ch << " " << int_num << " " << space << "\n";
		if (space == 0)
			break;
		space = 0;
		int_num = 0;
		large_ch = 0;
		small_ch = 0;
	}



	



	return 0;
}