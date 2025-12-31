#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v; // 누적 합이 아니라 원래 값을 저장
int max_val = 0; // 원소 중 최댓값 (이진 탐색의 시작점)
int total_sum = 0; // 전체 합 (이진 탐색의 끝점)

void input() {
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        total_sum += v[i];
        // 파라메트릭 서치의 lower bound는 '가장 큰 원소'여야 함 (그 원소 하나는 무조건 담을 수 있어야 하므로)
        if (max_val < v[i]) max_val = v[i]; 
    }
}

// 결정 함수: mid 값으로 M개 이하의 구간으로 나눌 수 있는가?
bool isPossible(int limit) {
    int cnt = 1; // 구간 개수 (첫 번째 구간 시작)
    int current_sum = 0;

    for (int i = 0; i < N; i++) {
        // 만약 값 하나가 limit보다 크면 절대 불가능 (이미 main에서 st를 max_val로 잡아서 방지되긴 함)
        if (v[i] > limit) return false; 

        if (current_sum + v[i] > limit) {
            // 현재 값을 더했을 때 제한을 넘으면, 여기서 구간을 끊음
            cnt++;
            current_sum = v[i]; // 새로운 구간의 시작은 현재 값
        }
        else {
            // 제한 안 넘으면 계속 더함
            current_sum += v[i];
        }
    }
    
    // 만들어진 구간 개수가 M개 이하인지 확인
    // (M개보다 적게 만들어졌다는 건, 더 널널하게 만들 수 있다는 뜻이니 성공)
    return cnt <= M;
}

int solve() {
    int st = max_val; // 시작값은 원소 중 최댓값
    int en = total_sum; // 끝값은 전체 합
    int ans = total_sum;

    while (st <= en) {
        int mid = (st + en) / 2;

        if (isPossible(mid)) {
            ans = mid;
            en = mid - 1; // 가능하니까 더 줄여보자 (최솟값을 찾으므로)
        }
        else {
            st = mid + 1; // 불가능하니까 값을 키워야 함
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << solve() << "\n";
    return 0;
}