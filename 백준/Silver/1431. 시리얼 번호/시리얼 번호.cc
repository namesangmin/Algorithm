#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<string> arr;
void input(){
    string str;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        arr.push_back(str);
    }
}
int getSum(const string& str){
    int Sum=0;
    for(int i=0; i< str.length(); i++){
        if(str[i] >= '0' && str[i] <='9'){
            Sum += (str[i] -'0');
        }
    }
    return Sum; 
}
bool cmp(const string& a, const string& b){
    // 1. A, B 중 길이 작은 거
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    if(a.length() == b.length()){
        int alen = getSum(a);
        int blen = getSum(b);
        // 2. A == B 중 A의 숫자 합, B의 숫자 합 중 작은 거
        if(alen != blen){
            return alen < blen;
        }

        // 3. A==B, A의 합 == B의 합 => 사전 순으로 
        return a < b;
    }
}

void func(){
    sort(arr.begin(), arr.end(), cmp);
}
void print(){
    for(int i=0; i<N; i++){
        cout << arr[i]<<"\n";
    }
}
int main(){
    input();
    func();
    print();
    return 0;
}