#include <iostream>
#include <cstring>
using namespace std;

int arr[100001];
bool visited[100001];
bool finish[100001];
int T, student, Count;
void dfs(int index) {
	visited[index] = true;
	int next = arr[index];
	if (!visited[next]) {
		dfs(next);
	}
	else if(!finish[next]) {
		for (int i = next; i != index; i = arr[i]) 
			Count++;
		Count++;
	}
	finish[index] = true;
}
void input() {
	cin >> T;
	while (T--) {
		Count = 0;
		cin >> student;
		// 초기화
		memset(visited, false, sizeof(visited));
		memset(finish, false, sizeof(finish));  

		// 입력
		for (int i = 1; i <= student; i++) {
			cin >> arr[i];
		}
		// dfs
		for (int i = 1; i <= student; i++) {
			if(!visited[i])
				dfs(i);
		}
		// 결과
		cout << student - Count << "\n";
	}
}
int main() {
	input();
}