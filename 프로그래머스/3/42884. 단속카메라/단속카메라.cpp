#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<bool> v;
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    int routesSize = routes.size();
    sort(routes.begin(), routes.end(), cmp);
    v.resize(routesSize, false);
    for(int i=0; i< routesSize; i++){
        int endP = routes[i][1];
        
        if(v[i]) continue;        
        
        for(int j = i; j < routesSize; j++){
            if(routes[j][0] > endP){
                i = j - 1;
                break;
            }
            else if(routes[j][0] <= endP && v[j] == false){
                v[j] = true;    
            }
        }
        
        answer++;
    }
    
    return answer;
}