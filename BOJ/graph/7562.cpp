/*
    [BOJ] 7562 나이트의 이동
    https://www.acmicpc.net/problem/7562
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[301][301];
int visit[301][301];
int T;
int ans, a,b;

typedef struct {
	int y;
	int x;
	int cnt;
}NIGHT;

const int dy[] = {-2,-1,2,1,2,1,-2,-1 };
const int dx[] = {1,2,1,2,-1,-2,-1,-2 };




void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void bfs(int y, int x) {
	queue<NIGHT> q;
	visit[y][x] = 1;
	NIGHT temp = { y,x,1 };
	q.push(temp);
	
	
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = temp.y + dy[i];
			int nx = temp.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] == 1)
				continue;

			if ((ny == a) && (nx == b)) {
				cout << temp.cnt << "\n";
				return;
			}
			if (visit[ny][nx]==false) {
				visit[ny][nx] = 1;
				NIGHT temp2 = { ny,nx,temp.cnt + 1 };
				q.push(temp2);
			}
			
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;

	while (T--) {
		memset(visit, 0, sizeof(visit));
		cin >> N;
		int y, x;			//나이트의 위치, 이동하려고 하는 칸
		cin >> y >> x >> a >> b;
		if ((y == a) && (b == x)) {
			cout << "0\n";
			continue;
		}
		bfs(y, x);
	}
	return 0;
}