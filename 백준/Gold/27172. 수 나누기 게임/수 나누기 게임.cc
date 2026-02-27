#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<int, int> card, scores;
vector<int> v;
int N;

// 1번부터 차례대로 비교하면
// 그러면 입력할 때의 수가 약수를 확인
// 그쪽에 카운트를 둔다
// 다음 입력에 일치하는 카드가 들어오면 위 단계를 똑같이 진행하되, 자기자신은 제외
// 마지막 scores 배려에 점수 출력
void input() {
    cin >> N;
    int tm;
    for (int i = 0; i < N; i++) {
        cin >> tm;
        card[tm] = 1;
        v.push_back(tm);
    }
}
void Check(int Card) {
    // 나누어 떨어지는 곳에 -1
    // 한번이라도 떨어지고, 그 숫자가 카드에 있으면
    // 자기 점수 +1
    // 1일 때 나머지를 구하면 무조건 자기 자신이 나옴
    for (int i = 1; i <= sqrt(Card); i++) {
        if (Card % i == 0) {
            // 만약 자신의 약수가 카드 중에 있으면 
            // 그 카드는 +1
            // 
            // 자기 자신은 -1
            if (Card != i && card.find(i) != card.end()) {
                scores[i]++;
                scores[Card]--;
            }
            if (Card / i != i && card.find(Card / i) != card.end() && (int)Card / i != Card) {
                scores[Card / i]++;
                scores[Card]--;
            }
        }
    }

}
void func() {

    for (auto itr = card.begin(); itr != card.end(); itr++) {
        int currentCard = itr->first;
        Check(currentCard);
    }
    for (int i = 0; i < N; i++) {
        int currentCard = v[i];
        int currentScore = scores[currentCard];
        cout << currentScore << " ";

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    func();
    return 0;
}