
/*
    [SWEA] 1210 Ladder1
 */
#include <iostream>
#include <cstring>
#define end "\n"
using namespace std;

int map[101][101];
int visit[101][101];
const int dy[] = { 0,0,-1 };
const int dx[] = { -1,1,0 };

int dstx;
int dsty= 99;
int srcx;
int T;
void input() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			cin >> map[i][j];
		}
	}
}
        
void findX() {
	for (int j = 0; j < 100; ++j) {
		if (map[99][j] == 2) {
			dstx = j;
		}
	}
}

void find(int sy, int sx) {
	int x = sx;
	int y = sy;
	while (y != 0) {
		for (int i = 0; i < 3; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= 100 || nx < 0 || nx >= 100)
				continue;
			if (visit[ny][nx])
				continue;

			if (map[ny][nx] == 1 && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				y = ny;
				x = nx;
			}
		}
	}
	srcx = x;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for (int num = 1; num <= 10; ++num) {
		cin >> T;
        memset(visit, 0, sizeof(visit));
        memset(map,0, sizeof(map));
        input();
		findX();

		visit[dsty][dstx] = 1;
		visit[dsty - 1][dstx] = 1;
		find(dsty - 1, dstx);

		cout <<"#"<<num<<" "<< srcx<<end;
	}
	return 0;
}