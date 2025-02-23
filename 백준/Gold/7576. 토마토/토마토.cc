#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue <pair<int,int>> q;
int M,N;
int g[1000][1000];
int K = 0; //익지 않은 토마토의 갯수
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void BFS(){
	while(!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//익지 않은 토마토가 있다면
		if ((nx >=0 && ny >= 0) && (nx < M && ny < N)) {
			if(g[ny][nx]==0) {
			g[ny][nx] = g[y][x] + 1;
			q.push({ny,nx});
			K--;
			}
		}//if문
		//더 이상 익은 토마토가 없으면
	
		}//for문
	
	}//while 문
}//void 함수
int main(){
	cin >> M >> N;
	K = M*N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//g[i][j] = 0; //초기화
			cin>>g[i][j];
			if (g[i][j] == -1)K--;
			else if (g[i][j] == 1){ K--; q.push({i,j});} //1(시작점 좌표)저장
		}//2중
	}//1중
	//생각 못함, 익은 토마토가 없을 때
	if (K == 0){cout << 0; return 0;}
	/*cout << "\n";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout <<i<<"," << j<<":"<< g[i][j] << "\n";
		}//2중
	}//1중
	*/
	BFS();//while문
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] == 0){cout<< -1; return 0;} //익지 못한 토마토가 있다면
			if (g[i][j] > result)result=g[i][j];
		}//2중
	}//1중
	cout << result-1;
	return 0;
}//main 함수