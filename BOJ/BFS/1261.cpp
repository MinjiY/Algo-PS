/*
    [BOJ] 1261 알고스팟
    https://www.acmicpc.net/problem/1261
*/
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int dist[101][101];

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	dist[y][x] = 0;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;

			if (map[ny][nx] == 1) {			//벽
				if (dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.push(make_pair(ny, nx));
				}
			}
			else if (map[ny][nx] == 0) {	//길
				if (dist[ny][nx] > dist[y][x]) {
					dist[ny][nx] = dist[y][x];
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}
int main(){
//	freopen("sample.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = 1e9;
		}
	}
	
	bfs(0, 0);
//	printDist();

	printf("%d\n", dist[N - 1][M - 1]);
//	fclose(stdin);
	return 0;
}
