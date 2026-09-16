#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> answer(2);

void makeAnswer(vector<vector<int>> nodeinfo){
    if(nodeinfo.empty()) return;
    int root;
    int idx = 0;
    int my = -1;
    for(int i=0; i<nodeinfo.size(); ++i){
        if(my < nodeinfo[i][1]){
            my = nodeinfo[i][1];
            root = nodeinfo[i][2];
            idx = i;
        }
    }

    answer[0].push_back(root);
    vector<vector<int>> left(nodeinfo.begin(), nodeinfo.begin()+idx);
    vector<vector<int>> right(nodeinfo.begin()+idx+1, nodeinfo.end());
    makeAnswer(left);
    makeAnswer(right);
    answer[1].push_back(root);

    return;
}

bool cmp(vector<int> a, vector<int> b){
    return a[0]<b[0]; // x기준 오름차순 정렬 (모든 x는 다른값)
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i=0; i<nodeinfo.size(); ++i){
        nodeinfo[i].push_back(i+1); // [2]에 노드번호 삽입
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);

    makeAnswer(nodeinfo);

    return answer;
}