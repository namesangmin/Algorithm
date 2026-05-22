#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(string a, string b){
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmArr;
    for(int i=0; i< numbers.size(); i++){
        string str = to_string(numbers[i]);
        tmArr.push_back(str);
    }
    sort(tmArr.begin(), tmArr.end(), cmp);
    if(tmArr[0] == "0") return "0";
    for(int i=0; i<tmArr.size(); i++){
        //cout << tmArr[i] << "\n";
        answer += tmArr[i];
    }
    
    return answer;
}