#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<vector<string>> group;
unordered_map<string, long long> company;
unordered_map<string, int> buy;
long long N, Q, g, B, C, D, E, P;
long long M;
char A[32];

void input() {
	cin >> N >> M >> Q;

	// 그룹 개수
	group.resize(101);

	for (int i = 0; i < N; i++) {
		cin >> g >> A >> P;
		// 회사 | 가격 
		company[A] = P;
		// 그룹 처리
		group[g].push_back(A);
	}
}

void menu1() {
	cin >> A >> B;
	long long companyPrice = 0;
	if (company.find(A) != company.end()) companyPrice = company[A];

	if (M >= B * companyPrice) {
		M -= B * companyPrice;
		buy[A] += B;
	}
}
void menu2() {
	cin >> A >> B;
	long long companyPrice = 0;
	if (company.find(A) != company.end()) companyPrice = company[A];

	// 안샀는데 팔라고 했을 수도 있음 => 예외처리
	if (buy.find(A) == buy.end()) return;

	int cnt = buy[A];
	if (cnt < B) {
		long long tmPrice = cnt * companyPrice;
		M += tmPrice;
		cnt = 0;
	}
	else {
		long long tmPrice = B * companyPrice;
		M += tmPrice;
		cnt -= B;
	}

	buy[A] = cnt;
}
void menu3() {
	cin >> A >> C;
	company[A] += C;
}
void menu4() {
	cin >> D >> C;
	for (int i = 0; i < group[D].size(); i++) {
		company[group[D][i]] += C;
	}
}
void menu5() {
	cin >> D >> E;

	for (int i = 0; i < group[D].size(); i++) {
		company[group[D][i]] = (company[group[D][i]] * (E + 100) / 100);
		company[group[D][i]] = company[group[D][i]] - company[group[D][i]] % 10;
	}
}
void menu6() {
	cout << M << "\n";
}
void menu7() {
	long long sum = 0;
	for (auto it = buy.begin(); it != buy.end(); it++) {
		sum += company[it->first] * it->second;
	}
	sum += M;
	cout << sum << "\n";
}

void func() {
	int menu;
	void(*menu_arr[7])() = { menu1, menu2,menu3,menu4,menu5,menu6,menu7 };
	for (int i = 0; i < Q; i++) {
		cin >> menu;
		menu_arr[menu - 1]();
	}
}
int main() {
	input();
	func();

	return 0;
}