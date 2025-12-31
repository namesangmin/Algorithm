#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> tree;
void init() {
	cin >> n >> m;
	// init
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		tree[i] = i;
	}
}
int Find(int node) {
	int nNode = tree[node];
	if(node == nNode) return node;
	return node = Find(nNode);
}
void Union(int aN, int bN) {
	// 다시 합치기
	int aNode = Find(aN);
	int bNode = Find(bN);
	tree[bNode] = aNode;

}

int func() {
	int ans = 0;
	int aN, bN;
	// union find
	for (int i = 0; i < m; i++) {
		cin >> aN >> bN;
		
		// parent 찾기
		if (Find(aN) != Find(bN)) {
			// 만약 parent가 다르면.. 합치기
			Union(aN, bN);
		}
		else { //만약 부모가 같으면 그게 정답
			ans = i + 1;
			break;
		}
	}

	return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	init();
	cout << func() << "\n";
	return 0;
}