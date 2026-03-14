#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, z;
long long func() {
	long long ans = -1;
	cin >> x >> y;
	z = ((y * 100) / x);
	long long Min = 0;
	long long Max = 1000000000;
	
	while (Min <= Max) {
		long long mid = (Min + Max) / 2;
		long long tmZ = ((y + mid) * 100 / (x + mid));
		
		// 변화 없음
		if (tmZ <= z) {
			Min = mid + 1;
		}
		else { // 변화 있음
			Max = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int main() {
	cout <<func();

	return 0;
}