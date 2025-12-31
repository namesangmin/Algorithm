#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int x1, y1, r1;
	int x2, y2, r2;

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int x_distance = x1 - x2;
		int y_distance = y1 - y2;
		double x_y_distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//cout << x_y_distance << "\n";
		// 무한 점
		if (x_y_distance == 0 && r1 == r2) {
			cout << "-1" << "\n";
		}
		// 한 점
		else if (x_y_distance == r1 + r2) {
			cout << "1" << "\n";
		}
		else if (x_y_distance == abs(r1-r2))
			cout << "1" << "\n";
		// 두 점
		else if (x_y_distance<r1+r2 && x_y_distance > abs(r1 - r2)) {
			cout << "2\n";
		}
		// 점 x
		else {
			cout << "0\n";
		}	
	}
	return 0;
}