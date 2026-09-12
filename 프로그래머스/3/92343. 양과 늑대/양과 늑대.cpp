#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
queue<int> q;
vector<vector<int>> vv;
int maxSp;

void eraseElement(int element, vector<int>& v){
    vector<int> tmV;
    for(int i=0; i< v.size(); i++){
        if(element == v[i]) continue;
        tmV.push_back(v[i]);
    }
    v = tmV;
}

void func(int cNode, int sheep, int wolf, const vector<int>& info, vector<int> v){
    
    maxSp = max(maxSp, sheep);
    
    for(int i=0; i<vv[cNode].size(); i++){
        int nNode = vv[cNode][i];
        
        v.push_back(nNode);
    }
    
    eraseElement(cNode, v);

    // for(int i=0; i< v.size(); i++){
    //     cout << v[i] << " ";
    // }
    // cout << " : ";
    
    for(int i=0; i< v.size(); i++){
        int nNode = v[i];
        int nVal = info[nNode];
           
        if(sheep > wolf + nVal){
            // cout << cNode << " " << nNode << " " << sheep << " " << wolf << "\n";
            
            if(nVal == 0){
                func(nNode, sheep + 1, wolf, info, v);
            }
            else if(nVal == 1){
                func(nNode, sheep, wolf + 1, info, v);
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int edSize = edges.size();
    int inSize = info.size();
    
    vv.resize(inSize);
    
    for(int i=0; i< edSize; i++){
        int st = edges[i][0];
        int ed = edges[i][1];
        
        vv[st].push_back(ed);
    }
    
    vector<int> v;
    v.push_back(0);
    
    func(0, 1, 0, info, v);
    answer = maxSp;
    return answer;
}