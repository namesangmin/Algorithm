#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string ch,ch2;
int dp[1000][2];

void input()
{
    cin >> ch >> ch2;
}

int main()
{
    input();
    int ch_Size = ch.size();
    int ch2_Size = ch2.size();
    int idx = 1, prev_idx = -1;
    // 같을 때
    // 1. 위 왼쪽 + 1 과 왼쪽 중에서 누가 더 큰가를 봄
    // 위 왼쪽에 있는 값을 가져와야 함

    // 그냥 위 + 1을 하면 그 전에 이미 그 문자를 포함해서 계산한 결과값에서 + 1을 하는 것과 같다.
    // CAJEI[A]
    // GCKHH[A] 
    // 0 1 1 1 [1] 1 
    // 0 1 1 1 [1] 2 
    // 0 1 1 1 [1] 2 
    // 0 1 1 1 [1] 2 
    // 0 1 1 1 [1] 2 
    // 0 1 1 1 [1] 2(3 x)

    // 다를 때
    // 1. 왼쪽과 위 중에서 뭐가 더 큰가

    // 배열의 인덱스 [idx = (idx+1) % 2]
    for(int i=0; i< ch_Size; i++)
    {
        idx ^= 1;
        prev_idx = idx  ^ 1;

        for(int j = 0; j <ch2_Size; j++)
        {
            int cur_line_left_val = 0, prev_line_left_val = 0, prev_line_val = 0;
            
            if(j - 1 >= 0){
                cur_line_left_val = dp[j - 1][idx]; // 왼쪽에 있는 거
                prev_line_left_val = dp[j -1][prev_idx]; // 위, 왼쪽에 있는 거
            } 
            prev_line_val = dp[j][prev_idx];

            if(ch[i] == ch2[j])
            {
                dp[j][idx] = max(cur_line_left_val, prev_line_left_val + 1);
            }
            else // 다르면 왼쪽 위 중에서 가져오기
            {
                dp[j][idx] = max(cur_line_left_val, prev_line_val);
            }
        }
    }
    cout << dp[ch2_Size - 1][idx] << "\n"; 
    return 0;
}