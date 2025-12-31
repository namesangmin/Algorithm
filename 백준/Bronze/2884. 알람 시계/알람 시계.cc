#include <iostream>
#define MINUTE 60

using namespace std;
int main(){
		int H, M,resultM = 0;
		cin >> H >> M;
		
		if (M < 45) {
			resultM = M + MINUTE - 45;
			H -= 1;
		}
		else 
			resultM = M - 45;

		if (H < 0) {
			H = 23;
		}
		cout << H << " " << resultM << "\n";
	
	return 0;
}