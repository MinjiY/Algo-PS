/*
    [BOJ] 14503 로봇 청소기
    https://www.acmicpc.net/problem/14503
 */
#include <iostream>
using namespace std;

int N, M;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int map[51][51];
//벽: 1 , 빈공간 : 0 , 청소한 자리: 2
int changeDir(int dir) {
	if (dir == 0) {
		return 3;
	}
	else if (dir == 1) {
		return 2;
	}
	else if (dir == 2) {
		return 0;
	}
	else if (dir == 3) {
		return 1;
	}
}
int numOfClean() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 2) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int y, x, dir;	
	
	cin >> y >> x >> dir;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}
	if (dir == 0) {
		dir = 3;
	}
	else if (dir == 1) {
		dir = 0;
	}
	else if (dir == 2) {
		dir = 2;
	}
	else if (dir == 3) {
		dir = 1;
	}


	while (1) {
		map[y][x] = 2;
		int d = dir;
		int cnt = 0;
		while (cnt<=3){
			d = changeDir(d);

			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				dir = d;
				break;
			}

			if (map[ny][nx] == 0) {
				y = ny;
				x = nx;
				dir = d;
				map[ny][nx] = 2;
				break;
			}
			cnt++;
		}
		if (cnt == 4) {
			y = y - dy[dir];
			x = x - dx[dir];
			if (map[y][x] == 1) {
				break;
			}
		}
	}
	
	cout << numOfClean() << "\n";
	return 0;
}