/*
    [BOJ] 5427 불
    https://www.acmicpc.net/problem/5427
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int T;
char map[1002][1002];
bool fvisit[1002][1002];
bool visit[1002][1002];

int fire[1002][1002];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
int ans;
//y,x, 종류, time
queue<pair<int, int>> q;

void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printFire() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << fire[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printpVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
//1: 불, 2: 상근이

void firebfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (fvisit[ny][nx])
				continue;

			if (map[ny][nx] == '.') {
				fvisit[ny][nx] = 1;
				fire[ny][nx] = fire[y][x]+1;
				q.push(make_pair(ny, nx));
			}
		}
	}

}
void bfs(int y, int x) {
	queue<pair<pair<int, int>, int>> q;
	visit[y][x] = 1;
	q.push(make_pair(make_pair(y, x), 0));
	
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				if (ans > cnt + 1) {
					ans = cnt + 1;
				}
				continue;
			}

			if (visit[ny][nx])
				continue;
			if (map[ny][nx] == '#')
				continue;

			if (fire[ny][nx] > cnt+1 ) {
				visit[ny][nx] = 1;
				q.push(make_pair(make_pair(ny, nx),cnt+1));
			}
			else if (map[ny][nx] == '.' && fire[ny][nx] == 0) {
				visit[ny][nx] = 1;
				q.push(make_pair(make_pair(ny, nx), cnt + 1));
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;

	while (T--) {
		memset(visit, 0, sizeof(visit));
		memset(fvisit, 0, sizeof(visit));

		memset(fire, 0, sizeof(fire));
		ans = 1e9;
		int start_y, start_x;
		cin >> M >> N;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					start_y = i;
					start_x = j;
					map[i][j] = '.';
				}
				else if (map[i][j] == '*') {
					q.push(make_pair(i, j));
					visit[i][j] = 1;
				}
			}
		}
		
		firebfs();
		bfs(start_y,start_x);
	
		if (ans == 1e9 || ans == 0) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << ans << "\n";
		}

	}
	return 0;
}