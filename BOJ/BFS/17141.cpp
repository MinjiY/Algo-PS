/* 
    [BOJ] 17141 연구소 2
    https://www.acmicpc.net/problem/17141
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct INFO {
	int y, x;
};
int N, M;
int ans=1e9;
int map[51][51];
int temp[51][51];
int dir[51][51];
int svisit[51][51];
int visit[51][51];
INFO selected[51];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printTemp() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << temp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void copyMap(int (*temp)[51]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			temp[i][j] = map[i][j];
		}
	}
}
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (svisit[ny][nx] == true)
				continue;

			if (map[ny][nx] == 0 || map[ny][nx] == 2 ) {
				svisit[ny][nx] = 1;
				temp[ny][nx] = temp[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}

	}

}
int cal() {
	int num = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 0 && temp[i][j] == 0) {
				return 1e9;
			}

				if (temp[i][j] > num) {
					num = temp[i][j];
				}
			
		}
	}
	return num;
}
void comb(int a,int b, int cnt) {
	if (cnt == M) {
		/*for (int i = 0; i < M; ++i) {
			cout << selected[i].y << " " << selected[i].x << "\n";
		}*/
		for (int i = 0; i < M; ++i) {
			
			q.push(make_pair(selected[i].y, selected[i].x));
			svisit[selected[i].y][selected[i].x] = 1;
		}
		bfs();
		int num = cal();
		if (ans > num) {
			ans = num;
		}
		//cout << ans << "\n";
		//printTemp();
		memset(svisit, 0, sizeof(svisit));
		memset(temp, 0, sizeof(temp));
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j =b; j < N; ++j) {
			if (map[i][j] == 2 &&visit[i][j]== 0) {
				visit[i][j] = 1;
			//	map[i][j] = 5;
				selected[cnt].y = i;
				selected[cnt].x = j;
				comb(i, j, cnt + 1);
				selected[cnt].y = 0;
				selected[cnt].x = 0;

				//	map[i][j] = 2;
				visit[i][j] = 0;
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	comb(0, 0, 0);
	if (ans == 1e9) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
	}
	return 0;
}
