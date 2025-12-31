#include <iostream>

using namespace std;

int people[51];
int know_people[51];
int people_number[51][51];
// (1) 진실을 알고 있는 사람이 담는 배열
// 서로 연결을 하고, 마지막에 파티의 개수를 셀 때,
// 자기 자신만 for문으로 확인을 하는데 그것이 (1)에 없으면 count
// 파티마다 (1)인 사람이 있는지 확인
// 있으면 (1)인 사람에게 연결

int find(int a) {
	if (a == people[a])
		return a;
	else {
		return people[a] = find(people[a]);
	}
}
void Union(int a, int b) {
	// 만약 사람이 파잘알이면 그쪽으로 연결
	// a가 파잘알일 때
	a = find(a);
	b = find(b);

	if (know_people[a] ) {
		people[b] = a;
	
	}
	// b가 파잘알일 때
	else if (know_people[b]) {
		people[a] = b;
	}
	// 아니면 그냥 연결
	else {
		if (a < b) {
			people[b] = a;
		}
		else {
			people[a] = b;
		}

	
	}
}

int main() {
	int n, m;
	int know_people_count;
	int come_party_people;
	// n : 사람, m : 파티
	cin >> n >> m;

	// 초기화
	for (int i = 1; i <= n; i++) {
		people[i] = i;
	}

	// 파잘알
	cin >> know_people_count;
	int input;
	for (int i = 0; i < know_people_count; i++) {
		cin >> input;
		know_people[input] = input;
	}

	// 파티 개수만큼 돈다.
	for (int i = 1; i <= m; i++) {
		// 파티 오는 사람 수
		cin >> come_party_people;
		people_number[0][i] = come_party_people;
		// 파티 오는 사람 이름
		for (int j = 1; j <= come_party_people; j++) {
			cin >> people_number[i][j];// 입력을 저장하는 배열이 필요한가?
		}
		// 4명일 때, 3번째까지만 연결하면 됨.
		for (int j = 1; j < come_party_people; j++) {
			int a = find(people_number[i][j]);
			int b = find(people_number[i][j + 1]);
			Union(a, b);
		}
	}

	int Count = 0;
	for (int i = 1; i <= m; i++) {
		bool isCount = true;
		int party_people = people_number[0][i];
		for (int j = 1; j <= party_people; j++) {
			if (know_people[find(people_number[i][j])]) {
				isCount = false;
				break;
			}
		}
		if (isCount)
			Count++;
	}
	
	std::cout << Count << "\n";
	return 0;
}