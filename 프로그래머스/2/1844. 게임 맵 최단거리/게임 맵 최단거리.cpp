#include<vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int bfs(int stX, int stY, vector<vector<int> > maps){
    vector<vector<bool>> visited;
    
    int mapSizeX = maps[0].size();
    int mapSizeY = maps.size();
    int tmAns = -1;
    visited.resize(mapSizeY, vector<bool>(mapSizeX));
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{stY, stX}});
    visited[stY][stX] = true;
    
    while(!q.empty()){
        int cx = q.front().second.second;
        int cy = q.front().second.first;
        int cnt = q.front().first;
        q.pop();
        
        if(mapSizeX - 1 == cx && mapSizeY - 1 == cy){
            if(tmAns < cnt){
                tmAns = cnt;
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
            
            if(nx < 0 || nx >= mapSizeX || ny < 0 || ny >= mapSizeY) continue;
            if(visited[ny][nx]) continue;
            if(maps[ny][nx] == 0) continue;
            visited[ny][nx] = true;
            q.push({cnt + 1, {ny,nx}});
        }
    }
    return tmAns;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(0,0, maps);
    return answer;
}