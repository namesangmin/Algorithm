#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<vector<int>> v;
vector<int> m;
queue<int>q;
void input() 
{
	int a, b;
	cin >> N >> M;
	v.resize(N + 1);
	m.resize(N + 1, -1);
	for (int i = 0; i < M; i++) 
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}
bool bfs(int node)
{
	q = queue<int>();
	q.push(node);
	while (!q.empty()) {
		int cNode = q.front();
		q.pop();

		for (int idx = 0; idx < v[cNode].size(); idx++)
		{
			int nNode = v[cNode][idx];
			if (m[cNode] == m[nNode]) return false;
			if (m[nNode] == -1) 
			{
				q.push(nNode);
				m[nNode] = m[cNode] ^ 1;
			}
		}
	}
	return true;
}
bool func()
{	
	for (int i = 1; i <= N; i++) 
	{
		if (m[i] == -1)
		{
			m[i] = 1;
			if (!bfs(i)) 
			{
				return false;
			}
		}
	}
	return true;
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	input();
	if (func()) cout << "1\n";
	else cout << "0\n";
	return 0;
}