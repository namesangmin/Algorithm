#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int firstP[5] = {1,2,3,4,5};
int secondP[8] = {2,1,2,3,2,4,2,5};
int thirdP[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr[3] = {0,};
    for(int i=0; i<answers.size(); i++){
        int c_ans = answers[i];
        if(firstP[i % 5] == c_ans){
            arr[0]++;
        }
        if(secondP[i % 8] == c_ans){
            arr[1]++;
        }
        if(thirdP[i % 10] == c_ans){
            arr[2]++;
        }
    }
    int tm = -1;
    
    for(int i=0; i<3; i++){
        if(arr[i] > tm){
            tm = arr[i];
        }
    }
    
    for(int i=0; i<3; i++){
        if(tm == arr[i])
            answer.push_back(i+1);
    }
    
    
    return answer;
    
}