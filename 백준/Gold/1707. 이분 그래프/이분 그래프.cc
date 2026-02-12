#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> flag;
int K, V, E;
bool func();
void input()
{
    cin >> K;
    int a, b;
    for (int k = 0; k < K; k++)
    {
        cin >> V >> E;
        v.assign(V + 1, vector<int>());
        flag.assign(V + 1, -1);
        for (int i = 1; i <= E; i++)
        {
            cin >> a >> b;
            v[a].push_back( b );
            v[b].push_back(a);
        }
        if (func()) cout << "YES\n";
        else cout << "NO\n";
    }
}
bool func()
{
    for (int i = 1; i <= V; i++)
    {
        if (flag[i] != -1) continue;

        queue<int> q;
        q.push(i);
        flag[i] = 1; 

        while (!q.empty())
        {
            int cNode = q.front();
            q.pop();

            for (int j = 0; j < v[cNode].size(); j++)
            {
                int n = v[cNode][j];
                if (flag[cNode] == flag[n]) {
                    return false;
                }

                if (flag[n] != -1) continue;

                q.push(n);
                flag[n] = flag[cNode] ^ 1; 
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
    return 0;
}