/*
    [BOJ] 14500 테트로미노
    https://www.acmicpc.net/problem/14500
 */

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int map[501][501];
bool visit[501][501] = { false, };
int n, m; //세로 가로
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int tetrimino(int x, int y, int cnt) {
	if (cnt >= 5) {
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (visit[nx][ny] == false) {
				visit[nx][ny] = true;
				ans = max(ans, tetrimino(nx, ny, cnt + 1)+map[x][y]);
				visit[nx][ny] = false;
			}
		}
	}
	return ans;

}
int exShape(int x, int y) {
	int ans = 0;
	// ㅏ
	if (x < n - 1 &&x>=1 && y < m - 1) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x - 1][y] + map[x][y + 1]);
	}
	// ㅓ
	if (x >= 1 && x < n-1 &&y >=1) {
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
	}
	// ㅗ
	if (x >= 1 && y>=1 && y < m - 1) {
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]);
	}
	// ㅜ
	if (y >= 1 && x < n - 1 && y < m - 1) {
		ans = (max(ans, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]));
	}

	return ans;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			ans = max(ans, exShape(i, j));
			ans = max(ans, tetrimino(i, j, 1));
			visit[i][j] = false;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}
