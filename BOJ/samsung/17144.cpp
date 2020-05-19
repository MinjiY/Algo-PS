/*
    [BOJ] 17144 미세먼지 안녕!
    https://www.acmicpc.net/problem/17144
 */
#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	int y;
	int x;
}INFO;
int N, M, T;
int map[52][52];
int dust[52][52];
INFO puri[2];

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void sumDust() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			map[i][j] += dust[i][j];
		}
	}
}
void rotate1() {
	int temp = 0;
	//서쪽
	for (int i = puri[0].y; i > 0; --i) {
		map[i][0] = map[i - 1][0];
	}
	//북쪽
	for (int j = 0; j < M - 1; ++j) {
		map[0][j] = map[0][j +1];
	}
	//동쪽
	for (int i = 0; i < puri[0].y; ++i) {
		map[i][M - 1] = map[i + 1][M - 1];
	}
	//남쪽
	for (int j = M - 1; j > 1; --j) {
		map[puri[0].y][j] = map[puri[0].y][j - 1];
	}
	map[puri[0].y][puri[0].x+1] = temp;
}
void rotate2() {
	int temp = 0;
	//서
	for (int i = puri[1].y; i < N-1 ; ++i) {
		map[i][0] = map[i +1][0];
	}
	//남
	for (int j = 0; j < M-1; ++j) {
		map[N - 1][j] = map[N - 1][j + 1];
	}
	//동
	for (int i = N - 1; i > puri[1].y; --i) {
		map[i][M - 1] = map[i - 1][M - 1];
	}
	//북
	for (int j = M-1; j > 0; --j) {
		map[puri[1].y][j] = map[puri[1].y][j - 1];
	}
	map[puri[1].y][1] = temp;
	
}
int numOfdust() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j]>0) {
				//cout << i << " " << j << "\n";
				cnt += map[i][j];
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int indx = 0;
	cin >> N >> M >> T;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				puri[indx].y = i;
				puri[indx].x = j;
				indx++;
 			}
		}
	}
	int cnt = 0;
	
	while (T--) {
		//먼지확산
		map[puri[0].y][puri[0].x] = -1;
		map[puri[1].y][puri[1].x] = -1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (map[i][j]>0) {
					cnt = 0;
					for (int k = 0; k < 4; ++k) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M)
							continue;

						if (map[ny][nx] !=-1) {
							dust[ny][nx] += (map[i][j] / 5);
							cnt++;
						}
					}
					map[i][j] = map[i][j] - ((map[i][j] / 5) * cnt);

				}
			}
		}
		//확산한먼지 + 기존먼지
		sumDust();
		memset(dust, 0, sizeof(dust));
		//공기청정	
		rotate1();
		rotate2();
	}
//	printMap();
	map[puri[0].y][puri[0].x] = 0;
	map[puri[1].y][puri[1].x] = 0;
	cout << numOfdust()<<"\n";
	return 0;
}