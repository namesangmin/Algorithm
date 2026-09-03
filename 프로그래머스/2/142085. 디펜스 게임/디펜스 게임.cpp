#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int vSize = enemy.size();
    int i;
    for(i=0; i< vSize; i++){
        
        n -= enemy[i];
        pq.push(enemy[i]);
        
        if(n < 0){
            if(k <=0) break;
            
            int cVal = pq.top();
            pq.pop();
            
            n += cVal;
            k--;
        }
        
    }
    
    answer = i;
    return answer;
}