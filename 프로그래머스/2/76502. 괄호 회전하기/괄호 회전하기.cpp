#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(const string& s, int strSize){
    stack<int> st;
    
    for(int i=0; i<strSize; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
           
            char tmCh = st.top();
            st.pop();
            
            if((tmCh == '(' && s[i] != ')') ||
               (tmCh == '[' && s[i] != ']') ||
               (tmCh == '{' && s[i] != '}')){
                
                return false;
            }
        }
    }
    
    if(!st.empty()) return false;
    return true;
}

string rotateStr(const string& s, int strSize){
    string nextStr = s;
    
    for(int i=0; i<strSize; i++){
        int nextIdx = (i + (strSize-1)) % strSize;
        nextStr[nextIdx] = s[i];
    }
   
    return nextStr;
}

int solution(string s) {
    int answer = 0;
    int strSize = s.size();
    int x = strSize;
    
    for(int i=0; i<strSize; i++){
        
        if(check(s, strSize)) answer++;
        
        s = rotateStr(s, strSize);
    }
    return answer;
}