#include <iostream>

using namespace std;

int Stack[500000];
int result[500000];
int top = -1;

void push(int data, int index) {
	Stack[++top] = data;
	result[top] = index;
}
void pop() {
	top--;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		
		if (i == 0) {
			push(input,i);
			cout << 0 << " ";
		}

		while (Stack[top] < input && top > -1) {
			pop();
		}

		if (top == -1) {
			cout << 0 << " ";
			push(input,i);
		}
		else if (Stack[top] > input) {
			cout << result[top]+1<< " ";
			push(input,i);
		}
	}
	return 0;
}