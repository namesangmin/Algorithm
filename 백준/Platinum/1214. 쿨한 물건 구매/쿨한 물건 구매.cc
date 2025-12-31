#include <iostream>
#include <algorithm>
using namespace std;
int D, P, Q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> D >> P >> Q;
	if (P > Q) swap(P, Q);

	int divByQ = D / Q;
	if (D > Q * divByQ) divByQ++;
	int ans = 2100000000;
	int maxL = min(P - 1, D / Q + 1);

	// divByQ가 몇 억이 나올 수 있음 -> 이거 어떻게 조정?
	for (int i = 0; i <= maxL; i++) {
		int diffD_Q = D - (i * Q);
		int curP_Val = (diffD_Q / P);

		if (diffD_Q <= 0) {
			ans = min(ans, i * Q);
			break;
		}

		// P의 바운더리... 
		if (curP_Val < 0) break;
		if (i * Q + curP_Val * P < D) curP_Val++;
		int curSum = i * Q + curP_Val * P;
		ans = min(ans, curSum);
	}
	cout << ans << "\n";
	return 0;
}