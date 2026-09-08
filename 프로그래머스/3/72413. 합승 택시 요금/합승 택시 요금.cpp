#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define INF 100000000

using namespace std;

vector<vector<pair<int,int>>> m;

void func(const int n, const int start, const vector<vector<int>>& fares, vector<int>& arr){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // 현재 합산 거리, 노드
    arr[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        auto [cVal, cNode] = pq.top();
        pq.pop();
        
        if(cVal > arr[cNode]) continue; // 이미 더 짧은 경로로 확정된 노드는 스킵

        for(int i=0; i< m[cNode].size(); i++){
            int nNode = m[cNode][i].first;
            int nE_Val = m[cNode][i].second;
            
            if(cVal + nE_Val < arr[nNode]){
                arr[nNode] = cVal + nE_Val;
                pq.push({arr[nNode], nNode});
            }
            
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<int> arrA, arrB, arrS;

    arrA.resize(n+1,INF);
    arrB.resize(n+1, INF);
    arrS.resize(n+1, INF);
    m.resize(n+1);
    
    for(int i=0; i<fares.size(); i++){
        int st = fares[i][0];
        int ed = fares[i][1];
        int val = fares[i][2];
        
        m[st].push_back({ed, val});
        m[ed].push_back({st, val});
    }
    
    func(n, a, fares, arrA);
    func(n, b, fares, arrB);
    func(n, s, fares, arrS);
    
    int tmAns = INF;
    for(int i=1; i< n+1; i++){
        if(arrA[i] + arrB[i] + arrS[i] < tmAns)
            tmAns = arrA[i] + arrB[i] + arrS[i];
    }
    
    answer = tmAns;
    return answer;
}