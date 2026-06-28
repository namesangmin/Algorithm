#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    int wkSize = works.size();
    int tm =0;
    for(int i=0; i<wkSize; i++){
        pq.push(works[i]);
        tm += works[i];
    }
    if(tm <= n) return answer;  
    
    while(n > 0){
        int cVal = pq.top();
        pq.pop();
        pq.push(cVal - 1);
        n--;
        
    }

    while(!pq.empty()){
        int cVal = pq.top();
        answer += (cVal * cVal);
        pq.pop();
    }
    return answer;
}