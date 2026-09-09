#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int n = 0;
    int pSize = players.size();
    
    vector<int> arr;
    arr.resize(pSize, 0);
    
    int prev = 0;
    
    for(int i=0; i< pSize; i++){
        
        if((n+1)*m <= players[i]){
            int val = (int)players[i] / m;
            val -= n;
            arr[i] = val;
            n += val;
        }
        
        if(i - prev >= k - 1) {
            n -= arr[prev];
            prev++; 
        }
        
        // cout << i << " " << prev << " " << arr[prev] << " " << players[i] << " " << n << "\n";
    }
    
    for(int i=0; i< pSize; i++){
        answer += arr[i];
    }
    
    
    return answer;
}