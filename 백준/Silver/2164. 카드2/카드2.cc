#include <iostream>
#include <vector>
using namespace std;

vector<int> sol(vector<int>& a, int prev) {	//짝수는 1 

	if (a.size() == 1)return a;

	vector<int> b;
	int i = 0, t;
	for (i=prev;i < a.size();i += 2) {
		b.push_back(a[i]);
		//std::cout << a[i] << '\n';
		if (i == a.size() - 1) {
			t = 1;
		//	cout << "t " << t << '\n';
		}
		else if (i == a.size() - 2) {
			t = 0;
		//	cout << "t " << t << '\n';
		}
		
	}
	if (b.size() > 1) {
		
		return sol(b, t);
	}
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	int N, a=0;
	cin >> N;
	a = N;
	int t;
    if(N ==1){cout <<1;
              return 0;
             }
	for (int i = 2;i <= N;i+=2) {
		v.push_back(i);
		//std::cout << i << '\n';
		if (i == N) {
			t = 1;
		//	cout << "t "<<t << '\n';
		}
		else if (i == N - 1) {
			t = 0;
		//	cout << "t " << t << '\n';
		}
	}
	//N이 짝수였으면 홀수, 홀수였으면 짝수 짝수는 0번부터 담고, 홀수는 1번부터 담는다. 
	v = sol(v, t);

	
	std::cout << v[0];
}