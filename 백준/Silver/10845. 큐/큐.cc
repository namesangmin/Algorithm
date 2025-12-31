#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main() {
	queue<int> queue_a;
	string get_char;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input = -1;
		cin >> get_char;
		if (get_char == "push") {
			cin >> input;
			queue_a.push(input);
		}
		else if(get_char == "front") {
			if (!queue_a.empty())
				cout << queue_a.front() << "\n";
			else
				cout << "-1" << "\n";
		}
		else if (get_char == "pop") {
			if (!queue_a.empty()) {
				int temp = queue_a.front();
				queue_a.pop();
				cout << temp << "\n";
			}
			else {
				cout << "-1" << "\n";
			}
		}
		else if (get_char == "size") {
			cout << queue_a.size() << "\n";
		}
		else if (get_char == "back") {
			if (!queue_a.empty())
				cout << queue_a.back() << "\n";
			else
				cout << "-1" << "\n";
		}
		else if (get_char == "empty") {
			cout << queue_a.empty() << "\n";
		}

		//cout <<"getchar : "<< get_char <<" input : " << input << "\n";
	}
	

	return 0;
}