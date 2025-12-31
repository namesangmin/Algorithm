#include <iostream>
#include <vector>
#include <utility>

using namespace std;

unsigned long long int Count;
vector<pair<int, int>> result;

void f(int n, int start, int work, int finish) {
    if (n == 1) {
        Count++;
        result.push_back({start, finish});
    } else {
        f(n - 1, start, finish, work);  // 첫 번째 장대에서 두 번째 장대로 이동
        Count++;
        result.push_back({start, finish});  // 첫 번째 장대에서 세 번째 장대로 이동
        f(n - 1, work, start, finish);  // 두 번째 장대에서 세 번째 장대로 이동
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int input;
    cin >> input;

    f(input, 1, 2, 3);  // 하노이 탑 이동

    cout << Count << "\n";  // 이동 횟수 출력
    
    for (const auto& move : result) {
        cout << move.first << " " << move.second << "\n";  // 이동 과정 출력
    }

    return 0;
}
