/*
    [BOJ] 2178 미로 탐색
    https://www.acmicpc.net/problem/2178
*/
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int cnt;

int visit[101][101];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

void input() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	pair<int, int> temp;

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M|| visit[ny][nx] ==1 ) continue;

			if (map[ny][nx] == 1) {
				visit[ny][nx] = 1;
				map[ny][nx] += map[temp.first][temp.second];
				q.push(make_pair(ny, nx));
			}

		}
	}

}
int main() {
	scanf("%d %d", &N, &M);
	input();
	
	bfs(0, 0);
	//printMap();
	printf("%d", map[N - 1][M - 1]);
	return 0;
}