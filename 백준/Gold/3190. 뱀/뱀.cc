#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;

int N, K, L, X;
// 우, 하, 좌, 상
int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 };
char C;
vector<vector<int>> board;
map<int, char> commands;
void input() {
	cin >> N >> K;
	board.resize(N+1, vector<int>(N+1, 0));
	
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		commands[X] = C;
	}
}
// L = 왼쪽으로 90도, D = 오른쪽으로 90도
int func() {
	int cmdTime = 0;
	int curDir = 0; // 처음 방향은 오른쪽
	deque<pair<int, int>> snake;
	snake.push_back({ 1,1 });
	board[1][1] = 2;
	while (true) {
		int cx = snake.back().second;
		int cy = snake.back().first;
		int nx = cx + dx[curDir];
		int ny = cy + dy[curDir];
		// 만약 자기자신이거나 벽이면 스탑
		if (nx < 1 || nx > N || ny < 1 || ny > N || board[ny][nx] == 2) break;
		// 만약 사과이면
		if (board[ny][nx] == 1) {
			snake.push_back({ ny,nx });
			board[ny][nx] = 2;
		}
		else { // 사과가 아니면
			int endX = snake.front().second;
			int endY = snake.front().first;
			snake.pop_front();
			snake.push_back({ ny,nx });
			board[endY][endX] = 0;
			board[ny][nx] = 2;
		}
		// 방향 조정 + ans 늘리기
		cmdTime++;
		auto it = commands.find(cmdTime);
		if (it != commands.end()) {
			if (it->second == 'D')  // 오른쪽으로 90
				curDir = (curDir + 1) % 4;
			else 
				curDir = (curDir + 3) % 4;
		}
	}
	return cmdTime + 1;
}
int main() {
	input();	
	cout << func() << "\n";
	return 0;
}