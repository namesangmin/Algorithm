#include <iostream>
#include <vector>
using namespace std;
int N, K, S, x, y;
int arr[201][201];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<pair<int, int>>> v_p;

void input() {
	cin >> N >> K;
	v_p.resize(K + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				v_p[arr[i][j]].push_back({ i,j });
			}
		}
	}
	cin >> S >> y >> x;
}

void func() {
	for (int i = 1; i <= S; i++) {
		vector<vector<pair<int, int>>> n_v_p(K + 1); 

		for (int j = 1; j <= K; j++) {
			int s = v_p[j].size();
			for (int k = 0; k < s; k++) {
				int stY = v_p[j][k].first;
				int stX = v_p[j][k].second;

				for (int d = 0; d < 4; d++) {
					int nx = stX + dx[d];
					int ny = stY + dy[d];
					if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
						if (arr[ny][nx] == 0) {
							arr[ny][nx] = j;
							n_v_p[j].push_back({ ny, nx });
						}
					}
				}
			}
		}
		v_p = n_v_p; 
	}
	cout << arr[y][x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}