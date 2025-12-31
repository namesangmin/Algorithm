#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v;
int N;
vector<int> func() {
	vector<int> ans (2);
	int Min = 2000000001;
	for (int i = 0; i < N - 1; i++) {
		int st = i + 1;
		int End = N - 1;
		int mid = 0;
		while (st <= End) {
			mid = (st + End) / 2;
			int result = v[i] + v[mid];
			
			// 여기서 계속 업데이트를 해줘야 함
			// 틀린 이유는 이 업데이트를 매번 해줘야 하는데 while 문 밖에서 해버리면 
			// 더 작은 값이 무시되고, 계속 움직이기 때문에 가장 작은 값을 구할 수가 없다.
			// 4
			// -10 5 12 20
			// -10 12 (정답)
			// -10 5 (출력값) -> 처음에 v[mid]가 12라서 정답이지만
			// result값은 양수이기 때문에 End = mid - 1;이 되어
			// -10 5가 나옴
			if (Min > abs(v[i] + v[mid])) {
				Min = abs(v[i] + v[mid]);
				ans[0] = v[i];
				ans[1] = v[mid];
			}
			if (result > 0) {
				End = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin >> N;
	int tm;
	for (int i = 0; i < N; i++) {
		cin >> tm;
		v.push_back(tm);
	}
	sort(v.begin(), v.end());

	vector<int> a = func();
	for (auto pr: a) {
		cout << pr << " ";
	}

	return 0;
}