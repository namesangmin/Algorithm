#include <iostream>

using namespace std;

int N;
long long k;

long long Count(long long curIdx) {
	long long cnt = 0;
	// 2중 for문 있으면 무조건 터지는데 -> 몫으로?

    long long tm = 0;
	for (int i = 1; i <= N; i++) {
		tm = (curIdx / i);
		if (tm > N) tm = N;
		cnt += tm;
        tm = 0;
    }
	return cnt;
}

long long func() {
	long long ans = 0;
	long long minIdx = 1, maxIdx = (long long)N * N;

	while (minIdx <= maxIdx) {
		long long mid = (minIdx + maxIdx) / 2;
		// mid 보다 작은 숫자가 몇 개가 있나?
		long long cnt = Count(mid);

		// 개수가 맞아 -> 근데 안에 그 값이 있는지 확인은?
		// k보다 개수가 많을 때 max값을 줄임
        // k보다 cnt가 넘으면 임시 저장
		if (cnt >= k) {
			maxIdx = mid - 1;
            ans = mid;
		}
		else {
			minIdx = mid + 1;
		}
	}
	return ans;
}
int main() {
	cin >> N >> k;
	cout << func() << "\n";
}