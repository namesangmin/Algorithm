#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> m;
void find_str(string& order, string current, int index, int len){
    if(len == current.size()){
        m[current]++;
        return;
    }
    
    for(int i = index; i< order.size(); i++){
        find_str(order, current + order[i], i + 1, len);
    }
}

bool cmp(const string& a, const string& b){
    return a < b;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    
    for(int c =0; c < course.size(); c++){
        m.clear();

       for(int i=0; i< orders.size(); i++){
           string tm = {};
           find_str(orders[i], tm, 0, course[c]);
       }
        
        int max_len = 0;
        for(auto a : m){
            if(a.second > max_len){
                max_len = a.second;
            }
        }
        
        if(max_len >=2){
            for(auto a : m){
                if(a.second == max_len){
                    answer.push_back(a.first);
                }
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}