#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct node{
    int x,y;
    int node;
}node;

typedef struct info{
    int x,y;
    int left, right;
}info;

vector<node> arr;
vector<info> T;

bool cmp(const node& a, const node& b){
    if(a.y > b.y){
        return true;        
    }
    else if(a.y == b.y && a.x < b.x){
        return true;
    }
    return false;
}

void func(int cNode, int cx , int cy, int rNode){
    
    if(cx < T[rNode].x){
        if(T[rNode].left == -1) {
            T[rNode].left = cNode;
        }
        else{
            func(cNode, cx, cy, T[rNode].left);
        }    
    }
    else{
        if(T[rNode].right == -1) 
            T[rNode].right = cNode;
        else{
            func(cNode, cx, cy, T[rNode].right);
        }    
    }
}
void preorder(int cNode, vector<int>& tmV){
    
    tmV.push_back(cNode);
    if(T[cNode].left != -1)
        preorder(T[cNode].left, tmV);
    if(T[cNode].right != -1)
        preorder(T[cNode].right, tmV);
    
}
void postorder(int cNode, vector<int>& tmV){

    if(T[cNode].left != -1)
        postorder(T[cNode].left, tmV);
    if(T[cNode].right != -1)
        postorder(T[cNode].right, tmV);
    
    // cout << cNode << " ";
    tmV.push_back(cNode);   
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int nSize = nodeinfo.size();
    
    for(int i=0; i<nSize; i++){
        arr.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1});
    }
    
    sort(arr.begin(),  arr.end(), cmp);

    // for(int i=0; i<nSize; i++){
    //     cout << arr[i].node << " : " << arr[i].x << " " << arr[i].y << "\n";
    // }
    
    T.resize(nSize + 1, {-1,-1,-1,-1});

    for(int i=0; i<nSize; i++){
        T[arr[i].node].x = arr[i].x;
        T[arr[i].node].y = arr[i].y;
    }
    
    int rootNode = arr[0].node;

    
    // for(int i=0; i< T.size(); i++){
    //     cout << T[i].x << " " << T[i].y << " " << T[i].left << " " << T[i].right << "\n";
    // }
    
    for(int i=1; i< nSize; i++){
        func(arr[i].node, arr[i].x, arr[i].y, rootNode);
    }
    
    // for(int i=0; i< T.size(); i++){
    //     cout << i<< " : " << T[i].left << " " << T[i].right << "\n";
    // }
    vector<int> tmV;
    preorder(rootNode, tmV);
    answer.push_back(tmV);

    tmV.clear();
    postorder(rootNode, tmV);
    answer.push_back(tmV);
    
    return answer;
}