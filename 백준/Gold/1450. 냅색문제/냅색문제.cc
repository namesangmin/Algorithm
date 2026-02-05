#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
vector<int> vec, setA, setB;
void input(){
    cin >> N >> C;
    int tm;
    for(int i=0; i<N;i++){
        cin >> tm;
        vec.push_back(tm);
    }
}
void dfs(int idx, int maxIdx, int sum, vector<int>& v){
    if(sum > C) return;
    if(idx >= maxIdx){
        if(sum <= C) v.push_back(sum);
        return;
    }
    dfs(idx + 1, maxIdx, sum, v);
    dfs(idx + 1, maxIdx, sum + vec[idx], v);
}
void makeSet(){
    dfs(0, N/2, 0, setA);
    dfs(N/2, N, 0, setB);    
    sort(setB.begin(), setB.end());
}
int func(){
    makeSet();
    
    int ans = 0;    
    // 개수 세기
    for(int i=0; i< setA.size(); i++){
        int setA_Val = setA[i];
        if(C - setA_Val >= 0){
            int ub = upper_bound(setB.begin(),setB.end(),C -setA_Val) - setB.begin();
            ans += ub;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << func() << "\n";
    return 0;
}