/*
    [BOJ] 2206 벽 부수고 이동하기
    https://www.acmicpc.net/problem/2206
 */
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int visit[1001][1001][2];
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}
void output() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int bfs() {
	queue<pair<pair<int,int>,pair<int,int>>> q;
	visit[0][0][0] = 1;

	q.push(make_pair(make_pair( 0,0),make_pair(0 ,1)));
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cut = q.front().second.first;
		int cnt = q.front().second.second;

		q.pop();

		if (y == N - 1 && x == M - 1) {
			return cnt;
		}

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (map[ny][nx] == 1 && cut == 0) {
				visit[ny][nx][cut+1] = 1;
				q.push(make_pair(make_pair( ny,nx),make_pair(cut + 1,cnt + 1)));
			}
			else if (map[ny][nx] == 0 && visit[ny][nx][cut] == 0) {
				visit[ny][nx][cut] = 1;
				q.push(make_pair(make_pair( ny,nx),make_pair(cut,cnt + 1)));
			}
		}
	}
	return -1;
}

int main() {
	input();
//	output();
	
	int ans = bfs();
	printf("%d\n", ans);
	return 0;
}
