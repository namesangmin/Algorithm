#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬
void qSort(int* arr, int L, int R, int N) {
	int orL = L;
	int orR = R;
	if (!(R <= L || L < 0 || R < 0)) {
		int pivot = L + rand() % (R - L + 1);
		while (L != R) {
			if (arr[L] < arr[pivot]) {
				L++;
			}
			else if (arr[R] >= arr[pivot]) {
				R--;
			}
			else {
				if (L == pivot) {
					pivot = R;
				}
				else if (R == pivot) {
					pivot = L;
				}
				int temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			}
		}
		int temp = arr[L];
		arr[L] = arr[pivot];
		arr[pivot] = temp;
		qSort(arr, orL, L - 1, N);
		qSort(arr, L + 1, orR, N);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	srand(time(NULL));

	int N = 0;
	cin >> N;
	int arr[1000001];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	qSort(arr, 0, N - 1, N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}