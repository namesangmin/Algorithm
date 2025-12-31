#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int T, x1, y1, x2, y2, x, y, r, n;
	cin >> T;

	while (T--){
		int result = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		while (n--){
			cin >> x >> y >> r;
			bool sP = sqrt(pow(x - x1, 2) + pow(y - y1, 2)) <= r;
			bool eP = sqrt(pow(x - x2, 2) + pow(y - y2, 2)) <= r;
			if (sP != eP)
				result++;
		}
		cout << result << "\n";
	}
}