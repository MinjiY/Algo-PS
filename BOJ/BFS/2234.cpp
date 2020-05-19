/*
    [BOJ] 2234 성곽
    https://www.acmicpc.net/problem/2234
*/
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

//서쪽에 벽이있으면 1 없으면 0

typedef struct {
	int wall[4] = { 0,0,0,0};
}INFO;
//서 북 동 남
const int dy[] = {0, -1, 0,1};
const int dx[] = { -1,0,1,0 };
int N, M;
int input[51][51];
INFO map[51][51];
int visit[51][51];
int sec_visit[51][51][2];
int roomsize;
int numOfroom;
int roommaxsize;
void printInput() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << input[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printsecVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 2; ++k) {
				cout << sec_visit[i][j][k] << " ";
			}
			cout << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				cout << map[i][j].wall[k] << " ";
			}
			cout << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void transforMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {

			for (int k = 0; k < 4; ++k) {
				if (input[i][j] & (1 << k)) {
					map[i][j].wall[k] = 1;
				}
			}
		}
	}
}
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx]) {
				continue;
			}
			if (map[temp.first][temp.second].wall[i] == 0) {
				visit[ny][nx] = 1;
			//	cout << ny << " " << nx << "\n";
				roomsize++;
				q.push(make_pair(ny, nx));
			}

		}

	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> input[i][j];
		}
	}
	//printInput();
	transforMap();
	//printMap();
	int ans = 0;
	int ans2 = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visit[i][j] == 0) {

				bfs(i, j);
				numOfroom++;
				roomsize++;
				if (ans < roomsize) {
					ans = roomsize;
				}
				roomsize = 0;
			}
		}
	}
	cout << numOfroom << "\n";
	cout << ans << "\n";
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
				for (int k = 0; k < 4; ++k) {
					memset(visit, 0, sizeof(visit));
					if (map[i][j].wall[k] == 1) {
						map[i][j].wall[k] = 0;
						bfs(i, j);
						roomsize++;
						if (ans2 < roomsize) {
							ans2 = roomsize;
						}
						roomsize = 0;
						map[i][j].wall[k] = 1;
					}
				}
		}
	}
	cout << ans2 << "\n";
	return 0;
}