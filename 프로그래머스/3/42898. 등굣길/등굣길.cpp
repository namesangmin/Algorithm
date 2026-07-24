#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int dx[2] = {0,1};
int dy[2] = {1,0};
int mx, my;

vector<vector<int>> Map;
int func(int x, int y){
    if(x < 1 || x > mx || y < 1 || y > my) return false;
    
    if(Map[y][x] == -1) return false;
    
    // 갔는데 어떤 값이 있음
    if(Map[y][x] != -2){
        return Map[y][x];
    }
    
    // n m 위치에 도달
    if(x == mx && y == my){
        return true;
    }
    
//     cout << x << " " << y << " " << prevX << " " << prevY << "\t";
//     cout << Map[y][x] << " " << Map[prevY][prevX] << "\n";
    Map[y][x] = 0;
    Map[y][x] += (func(x + 1, y) + func(x, y + 1)) % 1000000007;    
    
    return Map[y][x];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    Map.resize(n+1, vector<int>(m+1, -2));
    mx = m;
    my = n;
    
    for(int r=0; r<puddles.size(); r++){
        int x = puddles[r][0];
        int y = puddles[r][1];
        Map[y][x] = -1;
    }
    
    func(1,1);
    
    answer = Map[1][1];
    return answer;
}