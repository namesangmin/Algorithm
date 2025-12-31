#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v_p;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v_p.push_back(make_pair(a, b));  
    } 
    sort(v_p.begin(), v_p.end()); 
    for (auto pr : v_p) {
        cout << pr.first << " " << pr.second << "\n";
    }    
    return 0;
}
