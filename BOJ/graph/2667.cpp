/*
    [BOJ] 2667 단지번호붙이기
    https://www.acmicpc.net/problem/2667
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;
int N;
int map[26][26];
int visit[26][26];
int cnt = 0;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

void input() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = true;

	pair<int, int> temp;

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N||visit[ny][nx]== 1)	continue;

			if (map[ny][nx]) {
				visit[ny][nx] = true;
				cnt++;
				q.push(make_pair(ny, nx));
			}

		}
		
	}
}
int main() {
	int danji = 0;
	scanf("%d", &N);
	input();
//	printMap();
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j] && map[i][j] == 1) {

				cnt = 0;
				bfs(i, j);
				danji++;
				v.push_back(cnt);
			}
		}
	}
	printf("%d\n", danji);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		printf("%d\n", v[i]+1);
	}

	return 0;
}
