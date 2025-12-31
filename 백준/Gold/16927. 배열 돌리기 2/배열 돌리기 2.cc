#include <iostream>
#include <vector>
using namespace std;

int N, M, R, arr[301][301];

void input() {
	cin >> N >> M >> R;
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= M; col++) {
			cin >> arr[row][col];
		}
	}
}

static void moveArr() {
	int Count = min(N, M) / 2;
	vector<vector<int>> temp(301, vector<int>(301, 0));

	for (int i = 1; i <= Count; i++) {
		int min_r_index = i, min_c_index = i;
		int max_r_index = (N + 1) - i;
		int max_c_index = (M + 1) - i;

		int c_row = i, c_col = i;

		int loop_count = 2 * ((max_r_index - min_r_index) + (max_c_index - min_c_index)); 
		int rot = R % loop_count;

		for (int k = 0; k < loop_count; k++) {
			int value = arr[c_row][c_col];
			int n_row = c_row;
			int n_col = c_col;

			for (int r = 0; r < rot; r++) {
				if (n_col == min_c_index && n_row < max_r_index) {
					n_row++;
				}
				else if (n_row == max_r_index && n_col < max_c_index) {
					n_col++;
				}
				else if (n_col == max_c_index && n_row > min_r_index) {
					n_row--;
				}
				else if (n_row == min_r_index && n_col > min_c_index) {
					n_col--;
				}
			}

			temp[n_row][n_col] = value;

			if (c_col == min_c_index && c_row < max_r_index) {
				c_row++;
			}
			else if (c_row == max_r_index && c_col < max_c_index) {
				c_col++;
			}
			else if (c_col == max_c_index && c_row > min_r_index) {
				c_row--;
			}
			else if (c_row == min_r_index && c_col > min_c_index) {
				c_col--;
			}
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			arr[i][j] = temp[i][j];
}

void func() {
	moveArr();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	func();
	return 0;
}
