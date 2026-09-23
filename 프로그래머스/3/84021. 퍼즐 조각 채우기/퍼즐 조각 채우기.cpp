#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<vector<bool>> table_visited;
vector<vector<vector<pair<int,int>>>> v_p;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool normalize_and_check(const vector<pair<int,int>> tmBoard, vector<pair<int,int>> v_p){
    // 정규화
    int min_col= 51, min_row= 51;
    int vSize = v_p.size();
    int idx = 0;
    for(int i=0; i< vSize; i++){
        int cx = v_p[i].second;
        int cy = v_p[i].first;

        if(cy < min_row){
            min_col = cx;
            min_row = cy; 
        }
        else if(cy == min_row && cx < min_col){
            min_col = cx;
            min_row = cy; 
        }
    }
    
    vector<pair<int,int>> tm_v;
    for(int i=0; i<vSize; i++){
        int cx = v_p[i].second - min_col;
        int cy = v_p[i].first - min_row;
        tm_v.push_back({cy, cx});
    }
    
    // 확인
    int cnt =0;
    for(int i=0; i<vSize; i++){
        for(int j=0; j<vSize; j++){
            if(tm_v[i].second == tmBoard[j].second && tm_v[i].first == tmBoard[j].first){
                cnt++;
            }
        }

    }
    
    if(cnt == vSize) return true;
    return false;
}

void rotate(vector<pair<int,int>> v_p, vector<pair<int,int>>& return_v){
    int vSize = v_p.size();
    return_v.clear();
    
    for(int i=0; i< vSize; i++){
        int cx = v_p[i].second;
        int cy = v_p[i].first;

        return_v.push_back({cx, -cy});
    }
}

int check(vector<pair<int,int>> tmBoard, int cnt){
    bool isP = false;
    vector<vector<pair<int,int>>> tm_vvp = v_p[cnt];
    
    for(int i=0; i< tm_vvp.size(); i++){
        vector<pair<int,int>> check_vp, tm_vp = tm_vvp[i];
        
        for(int k=0; k<4; k++){
            // 우선 영점 맞춰서 확인
            if(table_visited[cnt][i]) break;
            
            isP = normalize_and_check(tmBoard, tm_vp);
            if(isP){
                table_visited[cnt][i] = true;
                return cnt;
            }
            
            // 안 맞으면 돌리기
            rotate(tm_vp, check_vp);
            tm_vp = check_vp;
        }
    }
    
    return 0;
}

int func(vector<vector<int>>& game_board, int r, int c){
    int gSize = game_board.size();
    int cnt = 1;
    game_board[r][c] = 1;
    
    vector<pair<int,int>> tm_v;
    tm_v.push_back({0,0});
    
    queue<pair<int, int>> q;
    q.push({r,c});
    
    while(!q.empty()){
        int cx = q.front().second;
        int cy = q.front().first;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= gSize || nx < 0 || ny >= gSize || ny < 0 || game_board[ny][nx] == 1)
                continue;
            
            game_board[ny][nx] = 1;
            tm_v.push_back({ny - r, nx - c});
            q.push({ny, nx});
            cnt++;
        }        
    }
    
    return check(tm_v, cnt);
}

void getDiagram(vector<vector<int>>& table, int r, int c){
    vector<pair<int,int>> tm_v;
    queue<pair<int,int>> q;
    
    q.push({r,c});
    table_visited[r][c] = true;
    
    int idx = v_p.size();
    tm_v.push_back({r,c});

    int tSize = table.size();
    int cnt = 1;
    while(!q.empty()){
        int cx = q.front().second;
        int cy = q.front().first;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
                        
            if(nx >= tSize || nx < 0 || ny >= tSize || ny < 0)
                continue;
            
            if(table[ny][nx] == 0 || table_visited[ny][nx] == true)
                continue;
            
            tm_v.push_back({ny,nx});
            table_visited[ny][nx] = true;
            cnt++;
            q.push({ny, nx});
        }
    }   
    v_p[cnt].push_back(tm_v);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int gSize = game_board.size();
    
    table_visited.resize(gSize, vector<bool>(gSize, false));
    v_p.resize(gSize * gSize);  
    
    for(int r=0; r<gSize; r++){
        for(int c=0; c<gSize; c++){
            if(table[r][c] == 1 && !table_visited[r][c]){
                getDiagram(table, r, c);
            }
        }
    }
    
    table_visited.assign(gSize * gSize, vector<bool>(gSize * gSize, false));

    for(int r=0; r<gSize; r++){
        for(int c=0; c<gSize; c++){
            if(game_board[r][c] == 0){
                answer += func(game_board, r, c);
            }
        }
    }
    
    return answer;
}