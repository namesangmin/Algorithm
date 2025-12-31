#include <iostream>
using namespace std;
int N;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        cout << "Case #" << i << ": "<< x+y << "\n";
    }
}