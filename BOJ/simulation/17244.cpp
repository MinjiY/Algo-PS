/*
    [BOJ] 17244 아맞다우산
    https://www.acmicpc.net/problem/17244
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int y, x;
}NODE;
int N, M;
char map[51][51];
int start_y, start_x;
int end_y, end_x;
vector<pair<int, int>> x;
bool selec[51];
NODE selected[51];
int ans=1e9;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int bfs(int y,int x,int ey,int ex) {
	int visit[51][51] = { 0, };
	queue<pair<pair<int, int>, int>> q;
	visit[y][x] = 1;
	q.push(make_pair(make_pair(y, x), 0));

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (y == ey && x == ex)	return cnt;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx])
				continue;
			
			if (map[ny][nx] == '.') {
				visit[ny][nx] = 1;
				q.push(make_pair(make_pair(ny, nx), cnt + 1));
			}
		}

	}
}
void permutation(int cnt) {
	if (cnt == x.size()) {
		int dist = 0;
		
		//S에서 첫번째 X까지
		dist = bfs(start_y, start_x, selected[0].y, selected[0].x);
			
		//얘네들 사이의 거리
		for (int i = 0; i < x.size()-1; ++i) {
			dist = dist + bfs(selected[i].y, selected[i].x, selected[i + 1].y, selected[i + 1].x);
		}
		//마지막 순서인애에서 end포인트까지 거리
		dist = dist + bfs(selected[x.size() - 1].y, selected[x.size() - 1].x, end_y, end_x);
		if (ans > dist) {
			ans = dist;
		}
		return;
	}
	for (int i = 0; i < x.size(); ++i) {
		if (selec[i] == false) {
			selec[i] = true;
			selected[cnt].y = x[i].first;
			selected[cnt].x = x[i].second;
			permutation(cnt + 1);
			selected[cnt].y = 0;
			selected[cnt].x = 0;
			selec[i] = false;
		}

	}
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				start_y = i; start_x = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'X') {
				x.push_back(make_pair(i, j));
				map[i][j] = '.';
			}
			else if (map[i][j] == 'E') {
				end_y = i; end_x = j;
				map[i][j] = '.';
			}
		}
	}

	if (x.size() == 0) {
		int dist = bfs(start_y, start_x,end_y,end_x);
		cout << dist << "\n";
		return 0;
	}
	else {
		permutation(0);
		cout << ans << "\n";
	}
    return 0;
}