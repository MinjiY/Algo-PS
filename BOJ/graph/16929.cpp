/*
    [BOJ] 16929 Two Dots
    https://www.acmicpc.net/problem/16929
*/
#include <cstdio>
#include <cstring>
using namespace std;

int N, M;				//세로 가로
int visit[52][52];
char map[52][52];
int check;
int ans;
int start_y, start_x;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };


void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

}
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void dfs(int y, int x,int cnt) {
	if (check) {
	//	printf("y:%d  x:%d \n",y,x );
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;

		if (!visit[ny][nx]) {
			if (map[y][x] == map[ny][nx]) {
				visit[ny][nx] = 1;
			//	printVisit();
				dfs(ny, nx, cnt + 1);
			}
		}
		else if (visit[ny][nx]) {
			if ((cnt >= 4) && (start_x == nx) && (start_y == ny)) {
				check = 1;
				return;
			}
		}
	

				
	}
}


int main() {
	scanf("%d %d", &N, &M);

	//input
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &map[i][j]);
		}
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!visit[i][j]) {
				memset(visit, 0, sizeof(visit));
				start_y = i;
				start_x = j;
				visit[i][j] = 1;
			//	printf("시작: %d %d\n", i,j);
				dfs(i, j, 1);
				if (check) {
					printf("Yes\n");
					return 0;
				}
			}
		}
	}

	printf("No\n");
	return 0;
}
