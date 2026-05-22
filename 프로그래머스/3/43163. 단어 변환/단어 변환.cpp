#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<bool> visited;

bool check(string a, string b){
    int diff = 0;
    
    for(int i=0; i< a.size(); i++){
        if(a[i] != b[i]) diff++;
    }
    if(diff == 1) return true;
    return false;
}

int bfs(string begin, string target, vector<string> words){
    int Ans = 0;
    queue<pair<int, string>> q;
    q.push({0,begin});
    
    while(!q.empty()){
        string cStr = q.front().second;
        int cnt = q.front().first;
        q.pop();
        
        if(cStr == target){
            Ans = cnt;
            break;
        }
        
        for(int i=0; i<words.size(); i++){
            if(visited[i]) continue;
            if(check(cStr,words[i])){
                visited[i] = true;
                q.push({cnt+1, words[i]});
            }
        }
    }
    
    
    return Ans;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int wdSize = words.size();
    int bgSize = begin.size();
    visited.resize(wdSize, false);
    answer  = bfs(begin, target, words);        
    
    return answer;
}