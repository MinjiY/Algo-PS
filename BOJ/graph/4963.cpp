/*
    [BOJ] 4963 섬의 개수
    https://www.acmicpc.net/problem/4963
*/
#include <iostream>
#include <cstring>
#include <queue>

#define end "\n"
using namespace std;

int map[50][50];
int result[50];
int visit[50][50];
int a, b, flag;
int cnt;
const int dx[] = { 0,0,-1,1 ,1, -1,-1 ,1};
const int dy[] = { -1,1,0,0 ,-1,1, -1,1};

void input() {
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			cin >> map[i][j];
		}
	}
}
void printMap() {
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			cout << map[i][j] << " ";
		}
		cout << end;
	}
	cout << end;
}
void printVisit() {
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << end;
	}
	cout << end;
}

void bfs(int y, int x) {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	pair<int, int> temp;
	
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		
		for (int i = 0; i < 8; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || ny >= b || nx < 0 || nx >= a) continue;

			if (visit[ny][nx]) continue;
			if (map[ny][nx] == 1) {
				visit[ny][nx] = 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	int indx = 0;
	while (!flag) {
		
		cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> a >> b;
		if (a == 0 && b == 0) {
			flag = 1;
			break;
		}
		input();

		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < a; ++j) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					visit[i][j] = 0;
;					bfs(i, j);
					++cnt;
				}
			}
		}
		result[indx] = cnt;
		indx++;
	}
	for (int i = 0; i < indx; ++i) {
		cout << result[i]<<end;
	}
	return 0;
}
