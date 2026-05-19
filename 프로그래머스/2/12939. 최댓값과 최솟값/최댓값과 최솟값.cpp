#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int str_size = s.length();
    string Min = "a";
    string Max = "";
    string tmp = "";
    int Min0 = 10000000, Max0 = -10000000;
    for(int i= 0; i < str_size; i++){
        if(s[i] == ' '){
            int tm = stoi(tmp);
            if(Min0 > tm){
                Min0 = tm;
            }
            if(Max0 < tm){
                Max0 = tm;
            }
            Min = to_string(Min0);
            Max = to_string(Max0);
//             if(Min > tmp){
//                 Min = tmp;

//             }
            
//             if(Max < tmp){
//                 Max = tmp;
//             }
            tmp = "";
            cout << "Min: " << Min << "\n";
            cout << "Max: " << Max << "\n";
            continue;
        }
        
        tmp.push_back(s[i]);
        cout << tmp << "\n";
    }
    
    int tm = stoi(tmp);
    if(Min0 > tm){
    Min0 = tm;
    }
    if(Max0 < tm){
    Max0 = tm;
    }
    Min = to_string(Min0);
    Max = to_string(Max0);
    
    cout << "Min: " << Min << "\n";
    cout << "Max: " << Max << "\n";
    answer = Min + " " + Max;   
    
    return answer;
}