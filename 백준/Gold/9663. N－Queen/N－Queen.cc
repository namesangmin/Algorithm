#include <iostream>

using namespace std;
int N;   
int arr[15];

bool promise9(int i){
	for (int j = 0; j < i; j++)	{
		if (arr[j] == arr[i] || abs(arr[i] - arr[j]) == (i - j))
			return false;
	}
	return true;
}

int N_queen(int& Count, int n){
	if (n == N) // 같으면 
		Count += 1;
	else {
		for (int i = 0; i < N; i++)	{ // 끝까지 탐색을 하는데
			arr[n] = i;	// 처음에는 0번 째, 두 번째는 1번 째 ... N-1 번째 까지 탐색
			// 열 기준이든 행 기준이든 상관 x 
			if (promise9(n)) // 열이 곂치는 게 있으면 재귀 x
				N_queen(Count, n + 1);
		}
	}
	return Count;
}

int main(){
	cin >> N;
	int result = 0;
	N_queen(result,0);
	cout << result << "\n";
	return 0;
}