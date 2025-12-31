#define _CRT_SECURE_NO_WARNINGS
#define MAX 200001
#include <iostream>
#include <map>

using namespace std;
map<string, int>map1;
int parents[MAX];
int Rank[MAX];

int getParents(int number) {
	if (parents[number] == number)
		return number;
	else {
		parents[number] = getParents(parents[number]);
		return parents[number];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case, F,a, b;
	char first_name[21];
	char second_name[21];

	cin >> test_case;



	for (int i = 0; i < test_case; i++) {
		// 초기화
		for (int i = 0; i < MAX; i++) {
			parents[i] = i;
			Rank[i] = 1;		// 모호하다는 오류가 뜸 그래서 ::를 붙힘
		}
		map1.clear();
		cin >> F;
		int count = 0; // 하하
		for (int j = 0; j < F; j++) {
			cin >> first_name >> second_name;

			if (map1.count(first_name) < 1)map1[first_name] = count++;
			if (map1.count(second_name) < 1)map1[second_name] = count++;


			a = getParents(map1[first_name]);
			b = getParents(map1[second_name]);
			//cout << a<< b << "\n";
			if(a != b) {
				int temp1, temp2;
				if (parents[a] != parents[b]) {
					temp1 = b;
					temp2 = a;

				}
				else {
					temp1 = a;
					temp2 = b;
				}
				parents[temp1] = temp2;
				Rank[temp2] += Rank[temp1];
				printf("%d\n", Rank[temp2]);
			}
			else {
				printf("%d\n", Rank[a]);
			}

			/*
			// 랭크 비교
			if (tempA > tempB) {
				parents[tempB] = tempA;
				//Rank[tempB] += Rank[tempA];

			}
			else if (tempA < tempB) {
				parents[tempA] = tempB;
				//Rank[tempA] += Rank[tempB];

			}
			else {
				parents[tempB] = tempA;
				Rank[tempA] += Rank[tempB];
			}



			// 출력
			if (Rank[tempA] > Rank[tempB]) {
				cout << Rank[tempA]<<"\n";
			}
			else {
				cout << Rank[tempB]<<"\n";
			}

			// 첫 번째
			if (map1.count(first_name)==0 && map1.count(second_name)==0) {
				map1[first_name] = 1;
				map1[second_name] = 1;
				
				tempA = getParents(map1[first_name]);
				tempB = getParents(map1[second_name]);

				parents[tempB] = parents[tempA];

			}
			else {
				tempA = getParents(map1[first_name]);
				tempB = getParents(map1[second_name]);

				if (tempA > tempB) {
					parents[tempB] = tempA;
				}else if (tempA < tempB) {
					parents[tempA] = tempB;
				}else{
					parents[tempB] = tempA;
					Rank[tempB] += Rank[tempA];
				}

			}*/
		}
		// 초기화
	}
	return 0;
}