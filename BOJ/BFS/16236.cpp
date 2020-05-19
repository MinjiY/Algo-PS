/*
    [BOJ] 16236 아기 상어
    https://www.acmicpc.net/problem/16236
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct NODE {
	int y;
	int x;
	int cnt;
};
struct INFO {
	int y;
	int x;
	int cnt;
	int size;
	int num;
};
int N;
int map[21][21];
int visit[21][21];

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

vector<NODE> v;
INFO shark;
//물고기 탐색하는 bfs
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
bool cmp(NODE p1, NODE p2) {
	if (p1.cnt < p2.cnt) {
		return true;
	}
	else if (p1.cnt == p2.cnt) {
		if (p1.y < p2.y) {
			return true;
		}
		else if (p1.y == p2.y) {
			if (p1.x < p2.x) {
				return true;
			}
		}
	}
	return false;
}
void bfs(int y, int x) {
	visit[y][x] = 1;
	queue<NODE> q;
	q.push({ y,x,0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visit[ny][nx] == 1) continue;

			if (map[ny][nx] < shark.size && map[ny][nx] !=0) {
				visit[ny][nx] = 1;
				v.push_back({ ny,nx,cnt+1 });
			}
			else if(map[ny][nx] == shark.size || map[ny][nx]==0 ){
				visit[ny][nx] = 1;
				q.push({ ny,nx,cnt+1 });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int y, x;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.y = i;
				shark.x = j;
				shark.cnt = 0;
				shark.size = 2;
				map[i][j] = 0;
			}
		}
	}
	while (1) {
		bfs(shark.y, shark.x);	//먹이찾기
		if (v.size() > 1) {
			sort(v.begin(), v.end(), cmp);
		}
		else if (v.size() == 0) {
			break;
		}

		//상어 정보 업데이트
		shark.y = v[0].y;
		shark.x = v[0].x;
		shark.cnt += v[0].cnt;
		shark.num++;
		if (shark.num == shark.size) {
			shark.num = 0;
			shark.size++;
		}
		//맵 정보 업데이트
		map[v[0].y][v[0].x] = 0;

		v.clear();
		memset(visit, 0, sizeof(visit));
	}
	cout << shark.cnt << "\n";

	return 0;
}
