#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<int> vec;
int N,x;
void input(){
    cin >> N;
    vec.resize(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cin >> x;
}

int func(){
    int ans = 0;
    for(int i=0; i<N-2; i++){
        int curVal = vec[i];
        int left = i+1, right = N-1;
        
        while(left <= right){
            int mid = (left + right)/2;
            int midVal = vec[mid];
            if(curVal + midVal == x){
                ans++;
                break;
            }
            
            if(curVal + midVal > x){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        
        }
    }

    return ans;
}
int main(){
    input();
    cout << func() << "\n";
}