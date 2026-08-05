#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) 
    {
        answer.push_back(-1);
        return answer;
    }
    else if(n == s)
    {
        for(int i=0; i<n; i++)
        {
            answer.push_back(1);
        }
        return answer;
    }
    else
    {
        int quo = s / n;
        int mod = s % n;
        for(int i=0; i< n; i++){
            answer.push_back(quo);
        }
        for(int i=0; i< mod; i++){
            answer[n - i - 1] += 1;
        }
    }
    
    return answer;
}