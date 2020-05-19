/*
    [SWEA] 탈주범 검거
    모의 SW 역량테스트
 */
#include <iostream>
#include <queue>
#include <cstring>
#define end "\n"
using namespace std;

int T;
int N, M;		//세로, 가로
int R, C, L;	//맨홀뚜껑의 세로, 가로, 

int map[51][51];
char visit[51][51];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << map[i][j] << " ";
		}
		cout << end;
	}
	cout << end;
}

struct node {
	int y, x, time;
	node(int _y, int _x, int _time) {
		y = _y;
		x = _x;
		time = _time;
	}
};

void bfs() {
	queue<node> q;
	q.push(node(R,C,1));
	visit[R][C] = 1;


	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int curTime = q.front().time;
		int curPipeType = map[y][x];
		q.pop();

		if (curTime == L) continue;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			int nextPipeType = map[ny][nx];

			if (nx < 0 || ny < 0 || ny >= N || nx >= M || nextPipeType == 0 || visit[ny][nx])
				continue;

			if (curPipeType == 2 && (i == 2 || i == 3)) continue;
			else if (curPipeType == 3 && (i == 0 || i == 1)) continue;
			else if (curPipeType == 4 && (i == 1 || i == 2)) continue;
			else if (curPipeType == 5 && (i == 0 || i == 2)) continue;
			else if (curPipeType == 6 && (i == 0 || i == 3)) continue;
			else if (curPipeType == 7 && (i == 1 || i == 3)) continue;

			if (i == 0) {
				if (nextPipeType == 1 || nextPipeType == 2 || nextPipeType == 5 || nextPipeType == 6) {
					visit[ny][nx] = 1;
					q.push(node(ny, nx, curTime+1));
				}
			}
			else if (i == 1) {
				if (nextPipeType == 1 || nextPipeType == 2 || nextPipeType == 4 || nextPipeType == 7) {
					visit[ny][nx] = 1;
					q.push(node(ny, nx, curTime+1));
				}
			}
			else if (i == 2) {
				if (nextPipeType == 1 || nextPipeType == 3 || nextPipeType == 4 || nextPipeType == 5) {
					visit[ny][nx] = 1;
					q.push(node(ny, nx, curTime+1));
				}
			}
			else{
				if (nextPipeType == 1 || nextPipeType == 3 || nextPipeType == 6 || nextPipeType == 7) {
					visit[ny][nx] = 1;
					q.push(node(ny, nx, curTime+1));
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	int tc;
	for (tc = 1; tc <= T; ++tc) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> map[i][j];
			}
		}

		bfs();

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (visit[i][j])
					ans++;
			}
		}

		cout <<"#"<<tc<<" "<<ans<<end;

	}
	return 0;
}