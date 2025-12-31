#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<string, string> Map; 
    for (int i = 0; i < N; i++) {
        string add, pw;
        cin >> add >> pw;
        Map[add] = pw;  
    }
    for (int i = 0; i < M; i++) {
        string find_add;
        cin >> find_add;
        cout << Map[find_add] << "\n";
    }
    return 0;
}
