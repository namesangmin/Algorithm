#include <iostream>
#include <queue>
#define MAX_STAIR 1000001
using namespace std;

void bfs(int tower, int start, int des, int up, int down) {
	bool visited[MAX_STAIR] = { false, };
	int ck[2] = { up, -down };
	queue<pair<int, int>>q_p;
	visited[start] = true;
	q_p.push({ start,0 });

	while (!q_p.empty()) {
		int current_stair = q_p.front().first;
		int current_dis = q_p.front().second;
		q_p.pop();

		if (current_stair == des) {
			cout << current_dis << "\n";
			return;
		}
		for (int i = 0; i < 2; i++) {
			int next_stair = current_stair + ck[i];
			if (next_stair > 0 && next_stair <= tower && !visited[next_stair]) {
				q_p.push({ next_stair, current_dis + 1 });
				visited[next_stair] = true;
			}
		}
	}
	cout << "use the stairs\n";
}

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	bfs(F, S, G, U, D);
	return 0;
}