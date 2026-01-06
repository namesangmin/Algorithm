#include <iostream>
#include <stack>
#include <string>
using namespace std;
void func() {
	stack<char> st;
	while (true) {
		while (!st.empty()) st.pop();
		char ch;
		bool isPossible = true;
		bool cnt = false;

		while (true) {
			ch = cin.get();
			if (ch == '\n')continue;
			if (ch == '.')break;
				
			cnt =true;
			if (ch == '[' || ch == '(') {
				st.push(ch);
			}
			if (ch == ']' || ch == ')') {
				if (!st.empty()) {
					char tmCh = st.top();st.pop();
					if (tmCh == '[' && ch == ']' || tmCh == '(' && ch == ')') continue;
					isPossible = false;
				}
				else isPossible = false;
			}
		}
		if (!cnt) break;
		if (isPossible && st.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	func();
	return 0;
}