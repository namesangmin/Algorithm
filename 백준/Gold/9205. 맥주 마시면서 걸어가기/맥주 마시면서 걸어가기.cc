#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t, n, x, y, fesX, fesY;
// 1 bottle = 50m
struct node {
	int x, y;
};
void bfs(const vector<node> & v_node) {
	int v_size = v_node.size();
	queue<node>q_node;
	bool visited[100] = {false,};

	visited[0] = true;
	q_node.push({ v_node[0].x,v_node[0].y});

	while (!q_node.empty()) {
		int cx = q_node.front().x;
		int cy = q_node.front().y;
		q_node.pop();
		if (abs(cx - fesX) + abs(cy - fesY) <= 1000) {
			cout << "happy\n";
			return;
		}
		for (int i = 1; i < v_size; i++) {
			int nx = v_node[i].x;
			int ny = v_node[i].y;
			if (!visited[i]) {
				if (abs(cx - nx) + abs(cy - ny) <= 1000) {
					visited[i] = true;
					q_node.push({ nx,ny });
				}
			}
		}
	}
	cout << "sad\n";
}
void input() {
	cin >> t ;
	for (int j = 0; j < t; j++) {
		cin >> n;
        vector<node>v_node;
		for (int i = 0; i <= n; i++) {
			cin >> x >> y;
			v_node.push_back({ x,y });
		}
		cin >> fesX >> fesY;
		bfs(v_node);
	}
}

int main() {
	input();
}