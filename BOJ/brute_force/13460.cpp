/*
    [BOJ] 13460 구슬 탈출2
    https://www.acmicpc.net/problem/13460
*/
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int N, M;

char map[11][11];
bool visit[11][11][11][11];
bool flag = false;

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
struct INFO {
	int blue_y;
	int blue_x;
	int red_y;
	int red_x;
};
struct point {
	int y;
	int x;
};
queue<pair<INFO,int>> q;
INFO gusul;

void printGusul(int by, int bx, int ry, int rx) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (by == i && bx == j) {
				cout << "B ";
			}
			else if (ry == i && rx == j) {
				cout << "R ";
			}
			else {
				cout << map[i][j] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}
int bfs() {
	visit[gusul.blue_y][gusul.blue_x][gusul.red_y][gusul.red_x] = true;
	
	while (!q.empty()) {
		int by = q.front().first.blue_y;
		int bx = q.front().first.blue_x;
		int ry = q.front().first.red_y;
		int rx = q.front().first.red_x;
		int cnt = q.front().second;
		q.pop();
	//	cout << by << " " << bx << " " << ry << " " << rx << "\n";
	//	cout << "기준맵\n";
	//	printGusul(by,bx,ry,rx);
		if (cnt >= 10) {
			return -1;
		}
		
		for (int i = 0; i < 4; ++i) {
			point blue = { by,bx };
			point red = { ry,rx };
			int nby = by + dy[i];
			int nbx = bx + dx[i];
			int nry = ry + dy[i];
			int nrx = rx + dx[i];

			if (nby < 0 || nbx < 0 || nby >= N || nbx >= M || nry < 0 || nrx < 0 || nry >= N || nrx >= M)
				continue;

			if (visit[nby][nbx][nry][nrx])
				continue;
			if (map[nby][nbx] == '#' && map[nry][nrx] == '#')
				continue;
			
			while (map[nry][nrx] == '.') {
				nry = nry + dy[i];
				nrx = nrx + dx[i];
			}
			red = { nry - dy[i], nrx - dx[i] };
			
			while (map[nby][nbx] == '.') {
				nby = nby + dy[i];
				nbx = nbx + dx[i];
			}
			blue = { nby - dy[i], nbx - dx[i] };
			if (map[nry][nrx] == 'O') {					//종료조건
				if (map[nby][nbx] == 'O') {

					continue;
				}
				else {
					return cnt + 1;
				}
			}
			else if (map[nby][nbx] == 'O') {
				continue;
			}
			else if (blue.y == red.y && blue.x == red.x) {
				int bluedis = abs(by - blue.y) + abs(bx - blue.x);
				int reddis = abs(ry - red.y) + abs(rx - red.x);

				if (bluedis > reddis) {		//블루가 이동한 경로 가 더 길면
					blue.y = blue.y - dy[i];
					blue.x = blue.x - dx[i];
				}
				else {
					red.y = red.y - dy[i];
					red.x = red.x - dx[i];
				}
			}
	//		printGusul(blue.y, blue.x, red.y, red.x);
			INFO temp = { blue.y,blue.x,red.y,red.x };
			visit[blue.y][blue.x][red.y][red.x] = 1;
	//		cout << "enqueue\n";
	//		cout << blue.y << " " << blue.x << " " << red.y << " " << red.x << "\n";

			q.push(make_pair(temp, cnt + 1));
	//		cout << "여기까지\n";

		}
		
	}
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				gusul.red_y = i;
				gusul.red_x = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				gusul.blue_y = i;
				gusul.blue_x = j;
				map[i][j] = '.';
			}
		}
	}
//	printGusul(gusul.blue_y, gusul.blue_x, gusul.red_y, gusul.red_x);
	q.push(make_pair(gusul,0));

	int ans = bfs();
	cout << ans << "\n";
	return 0;
}