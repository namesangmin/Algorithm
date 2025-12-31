#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N; 
vector<pair<int, int>> v_p;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> N;
	int first, second;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		v_p.push_back(make_pair(second, first));
	}
	sort(v_p.begin(), v_p.end());
	for (int i = 0; i < N; i++) {
		cout << v_p[i].second << " " << v_p[i].first << "\n";
	}
	return 0;
}