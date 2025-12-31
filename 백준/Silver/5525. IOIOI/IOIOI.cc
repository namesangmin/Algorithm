#include <iostream>
#include <stack>
using namespace std;

char ch_arr[1000001];

int main() {
    int n, m, result = 0;
    char ch;
    stack<char> ch_stack;

    cin >> n >> m;
    string s;
    cin >> s;

    int check_n = 2 * n + 1;  // PN 패턴 길이 (IOI... 반복)

    int counter = 0;  // IOI 패턴을 확인하는 카운터
    for (int i = 0; i < m; i++) {
        // I와 O가 교대로 나오는지 확인
        if (counter % 2 == 0 && s[i] == 'I') {  // 짝수번째 위치에 I
            ch_stack.push(s[i]);
            counter++;
        } else if (counter % 2 == 1 && s[i] == 'O') {  // 홀수번째 위치에 O
            ch_stack.push(s[i]);
            counter++;
        } else {
            // 패턴이 끊기면 스택 비우고, 다시 시작
            while (!ch_stack.empty()) ch_stack.pop();
            if (s[i] == 'I') {  // 끊긴 후 I로 다시 시작
                ch_stack.push(s[i]);
                counter = 1;
            } else {
                counter = 0;
            }
        }

        // 스택에 쌓인 패턴 길이가 2N+1일 때 (PN 패턴 완성)
        if (counter == check_n) {
            result++;   // 결과 증가
            ch_stack.pop();  // 중첩된 패턴을 처리하기 위해 I를 남겨둠
            ch_stack.pop();  // IO 패턴의 O 제거
            counter -= 2;    // 중첩을 고려해 두 칸 줄임
        }
    }

    cout << result << "\n";
    return 0;
}
