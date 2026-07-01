#include <string>
#include <vector>
#include <queue>
#define MAX 10000000
using namespace std;
vector<vector<int>> v;
vector<int> m;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    v.resize(n+1);
    m.resize(n+1, MAX);
    m[1] = 0;
    
    queue<int> q;
    q.push(1);
    
    for(int i=0; i<edge.size(); i++){
        int x = edge[i][0];
        int y = edge[i][1];
        
        v[x].push_back(y);
        v[y].push_back(x);
    }    
    
    while(!q.empty()){
        int cIdx = q.front();
        q.pop();

        int cSize = m[cIdx] + 1;
        for(int i=0; i< v[cIdx].size(); i++){
            int nIdx = v[cIdx][i];
            
            if(m[nIdx] > cSize){
                m[nIdx] = cSize;
                q.push(nIdx);
            }
        }
    }
    
    int tmMax = 0;
    for(int i =1; i< m.size(); i++){
        if(tmMax < m[i]){
            tmMax = m[i];
        }
    }
    
    for(int i=1; i< m.size(); i++){
        if(tmMax == m[i]) answer++;
    }
    return answer;
}