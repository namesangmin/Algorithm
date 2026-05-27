#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int> m;
void find_set(string order, string tm_memo, int idx, int c_course){
    if(c_course == tm_memo.size()){
        m[tm_memo]++;   
        return;
    }
    
    for(int i= idx; i< order.size(); i++){
        find_set(order, tm_memo + order[i], i + 1, c_course);
    }
}
bool cmp(const string& a, const string& b){
    return a < b;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i< orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
    }
    
    // 1. course의 개수는 몇 개 있나? -> map으로 개수를 셈 -> 그 중에서 가장 큰 값을 찾고, 
    // 2. 조합 중에서 큰 값과 일치하는게 뭔가?
    for(int idx = 0; idx < course.size(); idx++){
        int c_course = course[idx];
        m.clear();
        
        for(int o =0 ; o< orders.size(); o++){
            string tm = {};
            find_set(orders[o], tm, 0, c_course);
        }
        
            int max_cnt = 0;
            for(auto a : m){
                if(max_cnt < a.second){
                    max_cnt = a.second;
                }
            }
        
            if(max_cnt >= 2){
                for(auto a : m){
                    if(max_cnt <= a.second){
                        answer.push_back(a.first);
                    }
                }                
            }
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}