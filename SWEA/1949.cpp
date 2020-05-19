/*
    [SWEA] 1949 등산로 조성
    모의 SW 역량테스트
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define end "\n"

using namespace std;

int N, K;			//가로세로, 산 깎을 수 있는 갯수
int map[8][8];
int T;
int maxnum = 0;
int ans = 0;

int visit[8][8];
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };


void input() {
	memset(map, 0, sizeof(map));
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			maxnum = max(map[i][j], maxnum);
		}
	}
}
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << end;
	}
}

void dfs(int cnt,int y,int x,int cut) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (visit[ny][nx] == 1)
			continue;

		if (map[y][x] <= map[ny][nx]) {				//변환 위치 값이 현재위치보다 큰 경우
			if (cut == 0) {
				for (int depth = 1; depth <= K; ++depth) {
					int temp = map[ny][nx];
					int land = map[ny][nx] - depth;
					if (map[y][x] > land) {
						visit[ny][nx] = 1;
						map[ny][nx] = land;
						//cout << ny << " " << nx << " " << end;
						dfs(cnt + 1, ny, nx, cut+1);
						visit[ny][nx] = 0;
						map[ny][nx] = temp;
					}
				}
			}
			
		}
		else {
			visit[ny][nx] = 1;
			dfs(cnt + 1, ny, nx, cut);
			visit[ny][nx] = 0;
		}


		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		ans = 0;
		maxnum = 0;
		input();
		memset(visit, 0, sizeof(visit));
		//printMap();
		/*
		for (int i = 0; i < v.size(); ++i) {
			memset(visit, 0, sizeof(visit));
			temp = v[i];			//y,x
			dfs(1, temp.first, temp.second, 0);
		}*/
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j] == maxnum && visit[i][j] == 0) {
					visit[i][j] = 1;
					dfs(1, i, j, 0);
					visit[i][j] = 0;
				}

			}
		}

		cout <<"#"<<tc<<" "<<ans<<end;
	}


	return 0;
}