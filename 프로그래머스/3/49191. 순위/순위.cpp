#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int> check, re_check;
vector<vector<int>> win, lose;

void func(const int& cNode, const vector<vector<int>>& v, const int& n, vector<int>& memo){
    queue<int> q;
    vector<bool> visited;
    visited.resize(n+1, false);
    visited[cNode] = true;
    q.push(cNode);
    int tm = 0;
    
    while(!q.empty()){
        int cN = q.front();
        q.pop();
        
        for(int i=0; i< v[cN].size(); i++){
            int nNode = v[cN][i];
            if(!visited[nNode]){
                visited[nNode] = true;
                q.push(nNode);
                tm++;
            }
        }        
    }
    
    memo[cNode] = tm;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    win.resize(n+1);
    lose.resize(n+1);

    check.resize(n+1,0);
    re_check.resize(n+1,0);
    
    for(int i=0; i< results.size(); i++){
        int a = results[i][0];
        int b = results[i][1];
        win[a].push_back(b);
        lose[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        func(i, win, n, check);
        func(i, lose, n, re_check);
    }
    
    for(int i=1; i<=n; i++){
        //cout << check[i] << " " << re_check[i] << "\n";
        if(re_check[i] + check[i] == n - 1){
            answer++;
        }
    }
    
    return answer;
}