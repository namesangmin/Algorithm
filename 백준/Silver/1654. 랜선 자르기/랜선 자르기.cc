#include <iostream>
#include <algorithm>
using namespace std;

// k >> 이미 가지고 있는 랜선의 개수
// n >> 필요한 랜선의 개수
int line[10001];
int k, n;
unsigned int result;

int compare(const void * a, const void* b) {
	return *(int*)a - *(int*)b;
}

bool Count(int len) {
	int c = 0;
	for (int i = 0; i < k; i++) {
		c += (line[i] / len);
	}
	return c >= n;
}

void find() {
	unsigned int pc, pl, pr;
	
	pl = 1;
	pr = line[k - 1];
	
	while (pl <=pr) {
		pc = (pl + pr) / 2;
		if (Count(pc)) {
			result = max(result, pc);
			pl = pc + 1;
		}
		else {
			pr = pc - 1;
		}
	}
	cout << result << "\n";
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> line[i];
	}
	sort(line, line + k);
	find();
	return 0;
}