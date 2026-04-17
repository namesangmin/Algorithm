#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<char> st;

void printStack() {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
void storeStack(char ch) {
	st.push(ch);
}
int main() {
	string str;
	getline(cin, str);
	bool isSpecialCh = false;
	for (int i = 0; i < str.size(); i++) {
		char curCh = str[i];

		if (isSpecialCh && curCh != '>') {
			cout << curCh;
			continue;
		}
		// 시작
		if (curCh == '<') {
			isSpecialCh = true;
			printStack();
			cout << "<";
		}
		else if(curCh == '>') {
			isSpecialCh = false;
			cout << ">";
		}
		else if (curCh == ' ') {
			printStack();
			cout << " ";
		}
		else {
			storeStack(curCh);
		}
	}
	printStack();
	return 0;
}