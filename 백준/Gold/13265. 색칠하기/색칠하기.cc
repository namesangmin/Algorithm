#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v;
vector<int> flag;
int T,n,m;
bool func();
void input(){
    cin >> T;
    int x,y;
    for(int t=0; t<T; t++){
        cin >> n >> m;
        v.assign(n+1, vector<int>());
        flag.assign(n+1, -1);
        for(int i=0; i < m; i++){
            cin >> x >> y;
    
            v[x].push_back(y);

            v[y].push_back(x);
        }
        if(func()) cout << "possible\n";
        else cout << "impossible\n";
    }
}
bool func(){
    queue<int> q;
    
    for(int node=1; node<=n; node++){
        if(flag[node] != -1) continue;

        q.push(node);
        flag[node] = 1;
        
        while(!q.empty()){
            int cNode = q.front();
            int cVal = flag[cNode];
            q.pop();

            for(int i=0; i<v[cNode].size(); i++){
                int nNode = v[cNode][i];
                int nVal = flag[nNode];
                
                if(cVal == nVal) return false;
                if(flag[nNode] != -1) continue;
                
                flag[nNode] = cVal ^ 1;
                q.push(nNode);
            }
        }
    }
    return true;
}
int main(){
    input();
    return 0;
}