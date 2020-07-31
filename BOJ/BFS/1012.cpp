/*
	[BOJ] 1012 ¿Ø±‚≥Û πË√ﬂ
	https://www.acmicpc.net/problem/1012
*/
#pragma warning (disable: 4996)
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51];
int visit[51][51];
int N, M;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

//void printMap() {
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < M; ++j) {
//			cout << map[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visit[y][x] = 1;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx] == 1)
				continue;

			if (map[ny][nx] == 1) {
				visit[ny][nx] = 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T,K, ans=0;
	cin >> T;
	while (T--) {
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		ans = 0;
		cin >> M >> N >> K;
		
		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}