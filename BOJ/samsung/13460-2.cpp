/*
    [BOJ] 13460 구슬탈출2 
    https://www.acmicpc.net/problem/13460
 */
//1304KB 0ms
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int map[12][12];
int visit[12][12][12][12];
const int dy[] = {0,0,1,-1 };
const int dx[] = {1,-1,0,0 };
int ans;
typedef struct {
	int y, x;
}NODE;

NODE red;
NODE blue;
queue< pair<pair<NODE, NODE>, int>> q;
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int cnt;
void dirSelect() {
	int rny, rnx, bny, bnx;
	while (!q.empty()) {
		
		int q_size = q.size();

		while (q_size--) {
			NODE qred = q.front().first.first;
			NODE qblue = q.front().first.second;
			int qcnt = q.front().second;
			q.pop();

			if (map[qred.y][qred.x] == 'O' && map[qblue.y][qblue.x] != 'O') {
				//끝
				ans = cnt;
				return;
			}

			for (int i = 0; i < 4; ++i) {
				//red.y ~~~ 는 항상 시작정점의 위치
				red.y = qred.y;
				red.x = qred.x;
				blue.y = qblue.y;
				blue.x = qblue.x;

				//빨간구슬
				while (1) {
					rny = red.y + dy[i];
					rnx = red.x + dx[i];
					if (map[rny][rnx] == '#' || map[red.y][red.x] == 'O') break;
					red.y = rny;
					red.x = rnx;
				}
				
				//파란구슬
				while (1) {
					bny = blue.y + dy[i];
					bnx = blue.x + dx[i];
					if (map[bny][bnx] == '#' || map[blue.y][blue.x] == 'O') break;
					blue.y = bny;
					blue.x = bnx;
				}

				if (red.y == blue.y && red.x == blue.x) {
					if (map[blue.y][blue.x] == 'O') continue;
					if ((abs(qred.x - red.x) + abs(qred.y - red.y)) >
						(abs(qblue.x - blue.x) + abs(qblue.y - blue.y)))
					{
						red.y -= dy[i];
						red.x -= dx[i];
					}
					else {
						blue.y -= dy[i];
						blue.x -= dx[i];
					}
				}
				if (visit[red.y][red.x][blue.y][blue.x])
					continue;
				visit[red.y][red.x][blue.y][blue.x] = 1;
				q.push(make_pair(make_pair(red, blue),qcnt));
			}
		}
		if (cnt == 10) {
			ans = -1;
			return;
		}
		cnt++;
	}
	ans = -1;
	return;
}

int main() {
//	freopen("13460.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	NODE red;
	NODE blue;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				red.y = i;
				red.x = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				blue.y = i;
				blue.x = j;
				map[i][j] = '.';
			}
		}
	}
	q.push(make_pair(make_pair(red, blue),0));
	dirSelect();

	printf("%d\n", ans);
//	fclose(stdin);

	return 0;
}