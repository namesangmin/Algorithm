#include <iostream>
#include <vector>
#include <utility>

using namespace std;
unsigned long long int Count;
vector<pair<int, int>>result;
int arr[101];

void f(int n, int start, int work, int finish) {
	if (n == 1) {
		Count++;
		result.push_back({ start, finish });
		//printf("%d %d\n", start,finish);
	}
	else {
		f(n - 1, start, finish, work);
		Count++;
		result.push_back({ start, finish });
		//printf("%d %d\n", start,finish);
		f(n - 1, work, start, finish);
	}
}
int index;

void Not_f(int n) {
	arr[0] = 2;
	int carry = 0; // carry가 1이 되면 자리 올림
	for (int i = 0; i < n - 1; i++)
	{
		if (i == 0)
			arr[i] *= 2;
		for (int j = 0; j < i; j++)
		{
			arr[j] *= 2;
			arr[j] += carry;
			if (arr[j] >= 10) {
				carry = 1;
				arr[j] -= 10;
			}
			else
				carry = 0;
		}
	}

	arr[0] -= 1; // 1을 빼줌

	int start = 99;
	for (int i = 99; i > -1; i--)
	{
		if (arr[start] == 0) //시작부분을 구함
		{
			start--;
			continue;
		}

		cout << arr[i];
	}
}

// input이 1인 값을 가질 때 바로 3번으로 이동했다는 예외가 있음
// input이 2 이상의 값을 가지면 3번으로 이동함
// 함수 재귀식은 앞으로 가는 것, 뒤로 가는 것 2가지가 필요함
// 그리고 n==1일 때는 출력하는 것.
// 3, start, work, finish

int main() {
	iostream::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;
	
	if (input > 20) {
		Not_f(input);
	}
	else {
		f(input, 1, 2, 3);
		cout << Count << "\n";

		for (auto a : result) {
			cout << a.first << " " << a.second << "\n";
		}
	}
	// 이런 방법도 있음 
	/*for (int i = 0; i < result.size(); i++)
		//cout << result[i].first << " " << result[i].second << "\n";
		printf("%d %d\n", result[i].first, result[i].second);
	*/
	return 0;
}