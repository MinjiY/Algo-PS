/*
    [BOJ] 17143 낚시왕
    https://www.acmicpc.net/problem/17143
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int y, x;
	int speed, dir, size;
}INFO;
// 위 아래 오른쪽 왼쪽
const int dy[] = { 0, -1,1,0,0 };
const int dx[] = { 0,0,0,1,-1 };
int N, M, K;
INFO map[101][101];
vector<INFO> v;

void printMap() {
	cout << "속력 방향 크기\n";

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cout << map[i][j].speed << " " << map[i][j].dir << " " << map[i][j].size << "  ";
		}
		cout << "\n";
	}

}
void printVector() {
	cout << "속력 방향 크기\n";

	/*for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (v[i][j].size()) {
				for (int k = 0; k < v[i][j].size(); ++k) {
					cout << v[i][j][k].speed << " " << v[i][j][k].dir << " " << v[i][j][k].size << "  ";

				}
			}
			else {
				cout << "0 0 0  ";

			}

		}
		cout << "\n";
	}*/

}
int changeDir(int dir) {
	if (dir == 1)
		return 2;
	if (dir == 2)
		return 1;
	if (dir == 3)
		return 4;
	if (dir == 4)
		return 3;
}
void clearVector() {
	vector<INFO> temp;
	swap(temp, v);

}
void updateMap() {

	for (int i = 0; i < v.size(); ++i) {

		if (map[v[i].y][v[i].x].size) {
			if (map[v[i].y][v[i].x].size < v[i].size) {
				map[v[i].y][v[i].x].size = v[i].size;
				map[v[i].y][v[i].x].dir = v[i].dir;
				map[v[i].y][v[i].x].speed = v[i].speed;
			}
		}
		else {
			map[v[i].y][v[i].x].size = v[i].size;
			map[v[i].y][v[i].x].dir = v[i].dir;
			map[v[i].y][v[i].x].speed = v[i].speed;

		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r][c] = { r,c,s,d,z };
	}

	int king = 1;
	int sum = 0;
	while (king <= M) {
		if (K == 0) {
			break;
		}
		//낚시왕 이동
		for (int i = 1; i <= N; ++i) {
			if (map[i][king].size) {
				sum += map[i][king].size;
				map[i][king].size = 0;
				map[i][king].dir = 0;
				map[i][king].speed = 0;
				break;
			}
		}

		//상어이동
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (map[i][j].size) {
					int ny = i;
					int nx = j;
					int sp = map[i][j].speed;
					
					if (map[i][j].dir == 1 || map[i][j].dir == 2) {
						sp = sp % (2 * N - 2);
					}
					else if (map[i][j].dir == 3 || map[i][j].dir == 4) {
						sp = sp % (2 * M - 2);
					}

					while (sp--) {
						ny += dy[map[i][j].dir];
						nx += dx[map[i][j].dir];

						if (ny <= 0 || nx <= 0 || ny > N || nx > M) {
							ny -= dy[map[i][j].dir];
							nx -= dx[map[i][j].dir];
							map[i][j].dir = changeDir(map[i][j].dir);
							ny += dy[map[i][j].dir];
							nx += dx[map[i][j].dir];
						}
					}

					v.push_back({ny,nx ,map[i][j].speed,map[i][j].dir,map[i][j].size });
					map[i][j].speed = 0;
					map[i][j].dir = 0;
					map[i][j].size = 0;
				}
			}
		}
		updateMap();
		clearVector();
		king++;
	}
	cout << sum << "\n";

	return 0;
}
