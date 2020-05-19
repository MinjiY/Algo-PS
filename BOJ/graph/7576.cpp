/*
    [BOJ] 7576 토마토
    https://www.acmicpc.net/problem/7576
*/

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int n, m; // 배열의 크기

int a[1001][1001];
int d[1001][1001];


int dx[4] = { 0,0,-1,1 }; //행
int dy[4] = { 1,-1,0,0 }; // 열
// 동, 서, 북, 남

queue <pair<int, int>> q;
void printD() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void bfs() {

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;
					//printD();
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			d[i][j] = -1;
			if (a[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	bfs();
	int max = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[i][j] == -1 && a[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			if (max < d[i][j]) {
				max = d[i][j];
			}
		}
	}
	cout << max << "\n";
	return 0;
}