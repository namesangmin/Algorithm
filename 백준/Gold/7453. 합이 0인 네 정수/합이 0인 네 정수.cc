#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<int>a,b,c,d;
vector<int> setA, setB;
map<int,int> numSet;
int N, tmA,tmB,tmC,tmD;
void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmA >> tmB >> tmC >> tmD;
        a.push_back(tmA);
        b.push_back(tmB);
        c.push_back(tmC);
        d.push_back(tmD);
    }
}

long long check(){
    long long cnt = 0;
    for(int i=0; i<N*N; i++){
        int curA = setA[i];
        int left = 0, right = N*N-1;

        int firstIdx = lower_bound(setB.begin(),setB.end(),-curA) - setB.begin();
        int endIdx = upper_bound(setB.begin(),setB.end(),-curA) - setB.begin();
        cnt += (long long)(endIdx - firstIdx);
        
        // while(left <=right){
        //     int mid = (left + right)/2;
        //     int curB = setB[mid];

        //     cout << curA << " " << curB << "\n";
        //     if(curA + curB == 0){
        //         // 몇 개 있는지 확인해야 함.
        //         break;
        //     }

        //     if(curA + curB > 0){
        //         right = mid - 1;
        //     }
        //     else{
        //         left = mid + 1;
        //     }
        // }
    }
    return cnt;
}

long long func(){
    long long ans =0;
    int tmSetA = 0, tmSetB = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmSetA = a[i] + b[j];
            tmSetB = c[i] + d[j];
            setA.push_back(tmSetA);
            setB.push_back(tmSetB); 
        }
    }

    sort(setB.begin(),setB.end());

    ans = check();
    return ans;
}
int main(){
    input();
    cout << func() << "\n";
    return 0;
}