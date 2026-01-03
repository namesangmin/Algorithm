#include <iostream>
#include <vector>
#include <algorithm>
#define M_S_MAX_BOUND 7
#define M_S_MID 3
using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> squares;
vector<pair<int, int>> tmSquare;
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	visited.assign(M_S_MAX_BOUND, vector<bool>(M_S_MAX_BOUND));

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			cin >> arr[r][c];
		}
	}
}

// 0. 현재 도형 돌리기 0 -> 90 -> 180 -> 270

// 1. 도형 만들기
//		1.1 dx, dy 4개 되면 조사
//		1.1.1 중앙에서부터 시작해서 모든 경우의 수 구하기
//		1.2 [7 x 7] 벡터에 visited를 만들고, 4개가 만들어지면 list에 담기 
//		// 백트랙킹으로 만들면 될듯
// 	1.3 그러면 모두 다 만들고 검사하는 게 안 터지나?
// 
// 해당 좌표를 기준으로 도형 만들기?
// 좌표를 vector에 저장해서 검사를 해 해당 좌표에 있는 값
void makeSquare(int y, int x, int cnt) {
	if (cnt >= 4) {
		// 도형 담기
		vector<pair<int, int>> inputV;
		for (int i = 0; i < 4; i++) {
			int inputX = tmSquare[i].second - M_S_MID;
			int inputY = tmSquare[i].first - M_S_MID;
			inputV.push_back({ inputY,inputX });
		}
		squares.push_back(inputV);
		return;
	}
	
	// 90도 회전해서 담기
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visited[ny][nx]) {
			visited[ny][nx] = true;
			tmSquare.push_back({ ny,nx });
			makeSquare(ny, nx, cnt + 1);

			tmSquare.pop_back();
			visited[ny][nx] = false;
		}
	}
}
void fkShape() {
	squares.push_back({ {0,0} , {0,1}, {1,1}, {0,2} });
	squares.push_back({ {0,0} , {0,1}, {-1,1}, {0,2} });
	squares.push_back({ {0,0} , {1,0}, {1,-1}, {2,0} });
	squares.push_back({ {0,0} , {1,0}, {1,1}, {2,0} });
}
int check(int y, int x) {
	int calMax = 0;
	for (int i = 0; i < squares.size(); i++) {
		int tmSum = 0;
		for (int j = 0; j < squares[i].size(); j++) {
			int cx = x + squares[i][j].second;
			int cy = y + squares[i][j].first;

			if (cx < 0 || cx >= m || cy < 0 || cy >= n) break;
			tmSum += arr[cy][cx];
		}
		calMax = max(calMax, tmSum);
	}
	return calMax;
}

int func() {
	int ans = 0;
	visited[M_S_MID][M_S_MID] = true;
	tmSquare.push_back({ M_S_MID, M_S_MID });
	makeSquare(M_S_MID, M_S_MID, 1);
	fkShape();
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			ans = max(ans, check(r,c));
		}
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	cout << func() << "\n";
}