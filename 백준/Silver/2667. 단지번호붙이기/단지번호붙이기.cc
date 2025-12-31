#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool arr[26][26];
bool visited[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;
int Count;

queue<pair<int, int>> q_p;
int bfs(int x, int y) {
	int house_count = 0;

	q_p.push(make_pair(x, y));
	// 한 개가 카운트가 되지 않는 이유는 이 함수를 호출했을 때, 자기 자신이 포함되어야 하는데 포함되지 않고 바로 주변을 탐색 함.
	// 그러면 여기서에서 카운트를 하나 늘려주는 코드가 필요함..
	if (visited[x][y]) return false;
	else {
		visited[x][y] = true;
		//cout << "next_x" << x << " " << "next_y" << y << "\n";
		house_count++;
	}
	while (!q_p.empty()) {
		int current_x = q_p.front().first;
		int current_y = q_p.front().second;
		q_p.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];
			// 격자 이내 범위
			if ((next_x >= 0 && next_y >= 0) && (next_x < N && next_y < N)) {
				// 1인가? 1이면 넣기
				if (arr[next_x][next_y] && (!visited[next_x][next_y])) {
					visited[next_x][next_y] = true;
					q_p.push(make_pair(next_x, next_y));
					house_count++;
					//cout << "next_x" << next_x << " "<< "next_y" << next_y << "\n";
				}
			}
		}
	}
	return house_count;
}

int main() {
	vector<int> v;
	char ch;
	cin >> N;
	for (int i= 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			int temp = ch - '0';
			arr[i][j] = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] && !visited[i][j]) {
				int house = bfs(i, j);
				if (house > 0) {
					Count++; // 집합 개수 세기
					//cout << i << " " << j << "\n";
					//cout << house << "\n";
					v.push_back(house);
				}
			}
		}
	}
	cout << Count << "\n";
	sort(v.begin(), v.end());
	for (auto a : v) {
		cout << a << "\n";
	}
	return 0;
}