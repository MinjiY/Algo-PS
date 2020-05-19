/*
    [BOJ] 15686 치킨 배달
    https://www.acmicpc.net/problem/15686
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[51][51];
int visit[51][51];
int Min = 999999;
int ans = 999999;

typedef struct {
	int y, x;
}INFO;
typedef struct {
	int dis, num;
}house;

vector<int> v[51][51];
vector<INFO> list;			//치킨집
int numb = 0;
int selected[51];
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
bool cmp(house p1, house p2) {
	if (p1.dis < p2.dis)
		return true;
	return false;
}
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];

		}
	}
}
int getDistance(int r1, int r2, int c1, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visit[y][x] = 1;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;

			if (visit[ny][nx])
				continue;

			visit[ny][nx] = 1;
			if (map[ny][nx] == 1) {
				int dis = getDistance(y, ny, x, nx);
				v[ny][nx].push_back(dis);
				//v[y][x].push_back(dis);				//
			}
			q.push(make_pair(ny, nx));
		}
	}
}
void dfs(int indx, int cnt) {
	if (cnt == M) {
		
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (v[i][j].size()) {
					for (int k = 0; k < M; ++k) {
						if (Min > v[i][j][selected[k]])
						{
							Min = v[i][j][selected[k]];
						}
					}
					sum += Min;
					Min = 999999;
				}
			}
		}
		if (sum < ans) {
			ans = sum;
		}
		return;
	}

	for (int i = indx; i < numb; ++i) {
		selected[cnt] = i;
		dfs(i+1,cnt + 1);
		selected[cnt] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				list.push_back({ i,j});
				numb++;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 2) {	
				bfs(i,j);
				memset(visit, 0, sizeof(visit));
			}
		}
	}
		
	dfs(0, 0);
	cout << ans << "\n";

	return 0;
}