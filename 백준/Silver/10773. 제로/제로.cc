#include <iostream>

using namespace std;
int Stack[100001];

class stack_oper {
private:
	int top = -1;
public:
	void push(int data) {
		Stack[++(this->top)] = data;
	}
	void pop() {
		Stack[--(this->top)];
	}
	void total() {
		int sum = 0;
		for (int i = 0; i <= top; i++) {
			sum += Stack[i];
		}
		printf("%d", sum);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack_oper Stk = stack_oper();
	int K;
	unsigned int inputNum;
	
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> inputNum;
		if (inputNum == 0) {
			Stk.pop();
		}
		else {
			Stk.push(inputNum);
		}
	}
	Stk.total();
	return 0;
}