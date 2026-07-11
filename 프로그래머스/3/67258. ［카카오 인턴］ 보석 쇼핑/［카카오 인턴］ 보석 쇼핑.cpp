#include <string>
#include <vector>
#include <unordered_map>
#define MAX 1000000
using namespace std;

unordered_map<string, int> m;

int cntGems(const vector<string>& gems, const int& gemsSize){
    int cnt = 0;
    unordered_map<string, int> cntMap;
    for(int i=0; i<gemsSize; i++){
        auto it = cntMap.find(gems[i]);
        if(it == cntMap.end()){
            cntMap[gems[i]]++;   
            cnt++;
        }
    }
    return cnt;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int right = 0, left = 0;
    int ansRight =0, ansLeft = 0;
    int ansSize = MAX;
    int gemsSize = gems.size();
    
    // 기저
    int gemsCnt = cntGems(gems, gemsSize);
    int currentCnt = 0;
    while(right < gemsSize){
        m[gems[right]]++;
        if(m[gems[right]] == 1){
            currentCnt++;
        }
        right++;        

        while(currentCnt == gemsCnt){
            int tm = right - left;
            
            if(tm < ansSize) {
                ansSize = tm;
                ansLeft = left;
                ansRight = right;
            }
            m[gems[left]]--;
            if(m[gems[left]] == 0) currentCnt--;
            left++;
        }
        
    }
    
    answer.push_back(ansLeft + 1);
    answer.push_back(ansRight);
    return answer;
}