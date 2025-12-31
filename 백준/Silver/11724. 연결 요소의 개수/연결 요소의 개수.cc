#include <iostream>

using namespace std;
int arr[1001];


// 부모찾기 함수
// 입력 : 고아 ,고아 1개 
// return : 최종 부모, 부모 1개
// 구현 : 부모 x -> 자기 자신 return 자기 자신, 부모 o -> 다른 인덱스 , 최종 부모? if x 부찾 함수 호출 else return 부모 인덱스
// return 
// 함수는 입력값에 맞추면 안됨.
int find(int a) {
	// 부모 x
	if (arr[a] == a) {
		return a;
	}
	else return arr[a] = find(arr[a]);
}
// 합치기
// 입력 : 고아1, 고아2
// return : x
// 구현 : 무조건 작은 값이 부모
void union_1(int a, int b) {
	if (a < b) {
		arr[b] = a;
	}
	else {
		arr[a] = b;
	}
}

int main() {
	int n, m;
	int inputA, inputB;
	int count = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	
	}
	
	for (int i = 1; i <= m; i++) {
		cin >> inputA >> inputB;
		/*
		* 입력 노드 2개
		* 둘이 같은 트리인지 확인하기 위함 (find)
		* 
		*/
		int a = find(inputA);
		int b = find(inputB);
		if (a != b) {
			union_1(a, b);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == i)
			count++;
	}
	cout << count << "\n";
	return 0;
}