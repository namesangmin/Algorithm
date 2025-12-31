#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <iostream>
#include <map>

using namespace std;
int manitto[MAX];		// parents
int depths[MAX];
map<string, int>map1;

int Find(int number) {
	if (number == manitto[number]) {
		return number;
	}
	else {
		manitto[number] = Find(manitto[number]);
		return manitto[number];
	}
}

int main() {
	//int result = 0;
	int caseNumber = 1;
	while (true) {
		int N, parentF, parentS, rankF, rankS;
		int idx = 0;
		char first_name[11], second_name[11];
		int result = 0;

		for (int i = 0; i < MAX; i++) {
			manitto[i] = i;
			depths[i] = 0;
		}
		map1.clear();

		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			cin >> first_name >> second_name;
			if (map1.count(first_name) < 1)
				map1[first_name] = idx++;
			if (map1.count(second_name) < 1)
				map1[second_name] = idx++;


			parentF = Find(map1[first_name]);
			parentS = Find(map1[second_name]);
			rankF = depths[parentF];
			rankS = depths[parentS];

			if (parentF == parentS) {
				result++;
				continue;
			}

			if (rankF != rankS) {
				if (rankF > rankS) {
					manitto[parentS] = parentF;
				}
				else { // rankF < rankS
					manitto[parentF] = parentS;
				}
			}
			else { //rankF == rankS
				manitto[parentF] = parentS;
				depths[parentS]++;
			}
		}
		printf("%d %d\n", caseNumber, result);
		caseNumber++;
	} 
	/*
	for (int i = 0; i < result; i++) {
		printf("%d ", i + 1);
	}
	printf("\n");
	*/
	return 0;
}
