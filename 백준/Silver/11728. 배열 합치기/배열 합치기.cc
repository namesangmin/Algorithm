#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int A, B, fp = 0, sp = 0;
vector<int> arr_A;
vector<int> arr_B;
vector<int> arr_result;

void input() {
	cin >> A >> B;

	for (int i = 0; i < A; i++) {
		int temp;
		cin >> temp;
		arr_A.push_back(temp);
	}
	for (int i = 0; i < B; i++) {
		int temp;
		cin >> temp;
		arr_B.push_back(temp);
	}
}
void func() {
	while (fp < A && sp < B) {
		if (arr_A[fp] > arr_B[sp]) {
			arr_result.push_back(arr_B[sp++]);
		}
		else {
			arr_result.push_back(arr_A[fp++]);
		}
	}
	while (fp < A)
		arr_result.push_back(arr_A[fp++]);
	while (sp < B)
		arr_result.push_back(arr_B[sp++]);
    ostringstream out;
    for (int a : arr_result)
	    out << a << " ";
    cout << out.str();
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}