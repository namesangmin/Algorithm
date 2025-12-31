#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<unsigned int, unsigned int>> v_p;

int main() {
    cin >> N;
    unsigned int Start, End;

    for (int i = 0; i < N; i++) {
        cin >> Start >> End;
        v_p.push_back(make_pair(End, Start)); // 종료 시간 기준으로 정렬하기 위해 순서 변경
    }

    // 종료 시간이 빠른 순서대로 정렬
    sort(v_p.begin(), v_p.end());
    /*for (int i = 0; i < v_p.size(); i++) {
        cout << v_p[i].second << " " << v_p[i].first << "\n";
    }
    cout << "\n";*/
    int result = 0;
    unsigned int end_time = 0;

    for (int i = 0; i < N; i++) {
        // 현재 회의의 시작 시간이 마지막 종료 시간보다 늦거나 같으면 선택
        if (v_p[i].second >= end_time) {
           // cout << v_p[i].second << " " << end_time << "\n";
           // cout << "before count " << result << "\n";
            result++;
          //  cout << "after count " << result << "\n";
            end_time = v_p[i].first; // 마지막 종료 시간 갱신
           // cout << v_p[i].second << " " << end_time << "\n";
           // cout << "\n";
        }
    }

    cout << result << "\n";

    return 0;
}
