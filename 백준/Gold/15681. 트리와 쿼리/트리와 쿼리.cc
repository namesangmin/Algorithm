#include <iostream>
#include <vector>
using namespace std;
int N, R, Q;
struct node_info{
	vector<int> sub_tree_v;
	int score;
};
vector<node_info> v;
vector<int> ansQ;
void input() {
	cin >> N >> R >> Q;
	v.resize(N + 1);
	for (int i = 0; i < N-1; i++) {
		int U, V;
		cin >> U >> V;
		v[U].sub_tree_v.push_back(V);
		v[V].sub_tree_v.push_back(U);
	}
	for (int i = 0; i < Q; i++) {
		int temp;
		cin >> temp;
		ansQ.push_back(temp);
	}
}
void printAns() {
	for (int i = 0; i < Q; i++) {
		int how = ansQ[i];
		int answer = v[how].score;
		cout << answer << "\n";
	}
}
int calNode(int node, int parent = -1) {
	if (v[node].score != 0) return v[node].score;
	v[node].score = 1;

	for (int next : v[node].sub_tree_v) {
		if (next == parent) continue; 
		v[node].score += calNode(next, node);
	}
	return v[node].score;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	calNode(R); // R = Root Node
	printAns();
	return 0;
}