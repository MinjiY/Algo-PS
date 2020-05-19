/*
    [BOJ] 17836 공주님을 구해라!
    https://www.acmicpc.net/problem/17836
 */
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int T;
int map[102][102];
int visit[102][102][2];
//int temp[102][102];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
int ans;
bool flag = false;
void printMap() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cout<<  map[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}


void bfs() {
	queue<pair<pair<int, int>,pair<int, int>>> q;		//좌표, 그람
	q.push(make_pair(make_pair(0, 0),make_pair( 0,0)));

	visit[0][0][0] = 1;
	
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int gram = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (map[y][x] == 2) {
			gram = 1;
		}
		if (cnt > T) {
			flag = true;
			return;
		}
		if (y == N-1 && x == M-1) {
			
			ans = cnt;
			return;
		}
	
		for (int i = 0; i < 4; ++i) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx <0 || ny >= N || nx >= M)
				continue;

			
			if (gram == 1) {
				if (visit[ny][nx][gram] == 0) {
					visit[ny][nx][gram] = cnt+1;
					q.push(make_pair(make_pair(ny, nx), make_pair(gram, cnt+1)));
				}
			}
			else {
				if (visit[ny][nx][gram] == 0 && map[ny][nx] != 1) {
					visit[ny][nx][gram] = cnt+1;
					q.push(make_pair(make_pair(ny, nx), make_pair(gram,cnt+1)));
				}
			}
			
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("17836.txt", "r", stdin);
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}
	bfs();
//	if (ans >= 1 && ans <= T)	
//		cout << ans << "\n";
	if (flag) {
		cout << "Fail\n";
	}
	else if (ans == 0) {
		cout << "Fail\n";
	}
	else
		cout << ans << "\n";

	//fclose(stdin);
	return 0;
}