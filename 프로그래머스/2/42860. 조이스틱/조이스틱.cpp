#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<char, int> m;

void makeMap(string name){
    int val = 0;
    char ch = 'A';
    for(int i=0; i<=12; i++){
         m[ch++] = val++;
    }
    
    for(int i=13; i<=25; i++){
        m[ch++] = val--;
    }
}

int solution(string name) {
    int answer = 0;
    int nameSize = name.size();
    makeMap(name);
    
    int min_val = 3000;
    for(int i=0; i<nameSize; i++){
        answer += m[name[i]];
        int idx = i + 1;
        while(name[idx] == 'A') idx++;
        int tmp = min({nameSize -1, i*2 + nameSize - idx, i + 2 * (nameSize - idx)});
        if(min_val > tmp) min_val = tmp;
    }
    answer += min_val;
    return answer;
}