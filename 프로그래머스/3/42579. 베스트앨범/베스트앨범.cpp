#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
map<string, int> m;
map<string, vector<pair<int,int>>> mv;

bool cmp (const pair<int, int>& a, const pair<int,int>& b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    
    return a.first > b.first;
}

bool cmp2(const pair<string, int> &a, const pair<string, int>&b){
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int Size = genres.size();
    for(int i=0; i< Size; i++){
        string str = genres[i];
        int val = plays[i];
        
        if(m.find(str) == m.end()){
            //cout << str << "\t";
            m[str] = val;
            
            mv[str].push_back({val, i});
        }
        else{
            m[str] += val;
            mv[str].push_back({val, i});
        }
    }
    
    for(auto a : mv){
        sort(mv[a.first].begin(), mv[a.first].end(), cmp);    
    }
    
    // for(auto a : mv){
    //     for(int i=0; i< mv[a.first].size(); i++){
    //         cout << mv[a.first][i].first << " " << mv[a.first][i].second << "\n";
    //     }
    // }
    
    vector<pair<string, int>> v;
    for(auto a: m){
        v.push_back({a.first, a.second});
    }
    sort(v.begin(), v.end(), cmp2);
    
//     for(int i=0; i< v.size(); i++){
//         cout << v[i].first << " " << v[i].second << "\n";
//     }
    
    for(int j=0; j<v.size(); j++){
        string str = v[j].first;
        
        for(int i=0; i< mv[str].size(); i++){
            if(i >= 2) break;
            
            answer.push_back(mv[str][i].second);
        }
    }
    
    return answer;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          