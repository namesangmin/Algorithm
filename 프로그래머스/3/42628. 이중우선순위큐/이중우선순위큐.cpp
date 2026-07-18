#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
priority_queue<int>minPq, maxPq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i=0; i< operations.size(); i++){
        char curState = operations[i][0];
        string curVal = operations[i].substr(2);
        int val = stoi(curVal);
        
        if(curState == 'D'){
            if(minPq.empty() || maxPq.empty()) continue;
            
            if(val == -1){
                int minV = -minPq.top();
                minPq.pop();    
                
                
                priority_queue<int> tmPq;
                while(!maxPq.empty()){
                    int tmVal = maxPq.top();                
                    maxPq.pop(); 
                    
                    if(minV != tmVal){
                        tmPq.push(tmVal);
                    }
                }
                if(!tmPq.empty()){
                    maxPq = tmPq;
                }
            }
            else{                
                int maxV = -maxPq.top();
                maxPq.pop();    

                priority_queue<int> tmPq;
                while(!minPq.empty()){
                    int tmVal = minPq.top();                
                    minPq.pop(); 

                    if(maxV != tmVal){

                        tmPq.push(tmVal);
                    }
                }
                if(!tmPq.empty()){
                    minPq = tmPq;
                }

            }
        }
        else if(curState == 'I'){
            minPq.push(-val);
            maxPq.push(val);
        }
    
    }
    
    if(!minPq.empty() && !maxPq.empty()){
        int minV = -minPq.top();
        int maxV = maxPq.top();
        answer.push_back(maxV);
        answer.push_back(minV);
        
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}