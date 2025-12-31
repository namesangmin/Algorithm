#include <iostream>

using namespace std;
int node[27];
int Left[27];
int Right[27];

void merge(int p, int l_c, int r_c) {
	Left[p] = l_c;
	Right[p] = r_c;
	if (l_c != 0 && r_c == 0) {
		//printf("1\n");
		node[l_c] = p;
	}
	else if (l_c == 0 && r_c != 0) {
		//printf("2\n");
		node[r_c] = p;
	}
	else if(l_c != 0 && r_c != 0){
		//printf("4\n");
		node[l_c] = p;
		node[r_c] = p;
	}
	//cout << node[p] << " " << node[l_c] << " " << node[r_c] << "\n";
}
void pre(int start) {
	if (start == 0) return;
	cout << (char)(start + 'A' - 1); 
	pre(Left[start]);
	pre(Right[start]);             
}
void in(int start) {
	if (start == 0) return;
	in(Left[start]);
	cout << (char)(start + 'A' - 1); 
	in(Right[start]);
}
void post(int start) {
	if (start == 0) return;
	post(Left[start]);
	post(Right[start]);
	cout << (char)(start + 'A' - 1);
}
int main() {
	node[1] = 1; // 1 = A
	int N;
	char parent, left_child, right_child;
	cin >> N;
	int i_parent,i_left_child, i_right_child;

	for (int i = 1; i <= N; i++) {
		cin >> parent >> left_child >> right_child;

		i_parent = parent - 'A'+1;
		if (left_child == '.')
			i_left_child = 0;
		else
			i_left_child = left_child - 'A'+1;

		if (right_child == '.')
			i_right_child = 0;
		else
			i_right_child = right_child - 'A' + 1;

		//cout << i_parent << " " << i_left_child << " " << i_right_child;
		//printf("\n");
		merge(i_parent, i_left_child, i_right_child);
	}
	pre(1);
	cout << "\n";
	in(1);
	cout << "\n";
	post(1);

		/*cout << "\n";
	for (int i = 1; i <= N; i++) {
		cout <<i<<" "<< node[i] << " ";
		cout << node[2*i] << " ";
		cout << node[2 * i+1] << " ";
		cout << "\n";
	}*/

	return 0;
}