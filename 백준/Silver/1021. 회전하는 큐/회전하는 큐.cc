#include <iostream>

using namespace std;
int N, M, result, cArrayCount;
static int currentPointer = 1;
bool arr[51];

int findNum(int number) {
	int frontCount = 0;
	int backCount = 0;
	for (int i = 1; i < N; i++) {
		if (!arr[currentPointer]) {
			if (currentPointer == number) break;
			frontCount++;
		}
		currentPointer = (currentPointer == N) ? 1 : ++currentPointer;
	}
	backCount = cArrayCount - frontCount;
	arr[number] = true;	--cArrayCount;
	return (backCount > frontCount) ? frontCount : backCount;
}
void inputFunc() {
	cin >> N >> M;
	cArrayCount = N; // 처음에는 N개 
	for (int i = 0; i < M; i++) {
		int tempGet;
		cin >> tempGet;
		result += findNum(tempGet);
	}
	cout << result << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inputFunc();
	return 0;
}