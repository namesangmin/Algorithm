#define MAX 35
#include <iostream>
#include <cstring>

using namespace std;
int dp[45];
char input[45];
int input_to_arr[45];
int end_index;
int f(int index, int n) {
	if (index > end_index)
		return 1;

	if (dp[index] != -1) {
		return dp[index];
	}

	dp[index] = 0;

	if (n != 0) {
		dp[index] += f(index + 1, input_to_arr[index + 1]);
		int a = 10 * input_to_arr[index] + input_to_arr[index + 1];

		if (a < MAX && index < end_index )dp[index] += f(index + 2, 10 * input_to_arr[index] + input_to_arr[index + 1]);
	}
	return dp[index];
}
// 문자열을 입력 받아서 숫자로 변환 시켜줘야 함. 처음에 문자열 인덱스를 보내서 하려고 했는데 아이디어가 떠오르지가 않음.
int main() {
	cin >> input;
	for (auto& a : dp)a = -1;
	for (int i = 0; i < strlen(input); i++) {
		input_to_arr[i + 1] = input[i] - '0';
	}
	end_index = strlen(input);
	int result = f(1, input_to_arr[1]);
	cout << result << "\n";
	return 0;
}