#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<bool>> visited;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int row,col;

bool bfs(int r, int c, vector<string> m){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{r,c}});
    visited.assign(row, vector<bool>(col, false));
    visited[r][c] = true;
    
    while(!q.empty()){
        int cx = q.front().second.second;
        int cy = q.front().second.first;
        int moveCnt = q.front().first;
        q.pop();
        
        if(moveCnt >= 2) continue;
        
        for(int i=0; i< 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < col && ny >= 0 && ny < row && !visited[ny][nx] && m[ny][nx] != 'X'){
                visited[ny][nx] = true;
                if(m[ny][nx] == 'P'){
                    return false;
                }                
                q.push({moveCnt + 1,{ny,nx}});
            }
        }
        
        
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    row = places[0].size();
    col =places[0][0].size();
    
    for(int i=0; i< places.size(); i++){
        // visited.assign(row, vector<bool>(col,false));
        bool isP = true;
        for(int r=0; r< row; r++){
            for(int c=0; c<col; c++){
                if(places[i][r][c] == 'P' && isP){
                    isP = bfs(r,c,places[i]);     
                    if(!isP) break;
                }
            }
        }
        answer.push_back(isP);
    }
    return answer;
}