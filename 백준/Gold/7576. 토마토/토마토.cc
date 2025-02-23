#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> g;
int M, N;

void bfs() { 
    while (!g.empty()) {
        int current_x = g.front().first;
        int current_y = g.front().second;
        g.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if ((next_x >= 0 && next_y >= 0) && (next_x < N && next_y < M)) { 
                if (arr[next_x][next_y] == 0) {  
                    arr[next_x][next_y] = arr[current_x][current_y] + 1;
                    g.push(make_pair(next_x, next_y));	
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;
    
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) 
                g.push(make_pair(i, j));
        }
    }

    bfs(); 

    int result = 0;
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {  
                cout << "-1\n";
                return 0;
            }
            result = max(result, arr[i][j]); 
        }
    }

    cout << result - 1 << "\n"; 
    return 0;
}
