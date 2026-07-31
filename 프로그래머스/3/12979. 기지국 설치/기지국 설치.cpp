#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int div = 2*w + 1;
    int pMin = 0;
    int pMax = 0;
    int cSta, cMin, cMax;
    
    for(int i=0; i< stations.size(); i++){
        cSta = stations[i];
        cMin = cSta - w;
        cMax = cSta + w;
        
        if(cMax > n){
            cMax = n;
        }
        
        int tmVal = (cMin - pMax - 1) / div;
        if((cMin - pMax - 1) % div > 0) tmVal++;
        if((cMin - pMax - 1 <= 0)) tmVal = 0;
        answer += tmVal;

        
        pMin = cMin;
        pMax = cMax;
    }
    
    if(pMax < n){
        int tmVal = (n - pMax) / div;
        if((n - pMax) % div > 0) tmVal++;
        answer += tmVal;
    }


    return answer;
}