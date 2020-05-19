/*
    [SWEA] 미로 1
*/
#include <cstdio>
#include <cstring>


int map[16][16];
int visit[16][16];

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int ans;
void input() {
	int number;
	scanf("%d", &number);
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}
void printMap() {
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printVisit() {
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void dfs(int y, int x) {
	if (map[y][x] == 3) {
		ans = 1;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];


		if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16)
			continue;

		if ((!visit[ny][nx]) && (map[ny][nx] == 0) ||(map[ny][nx] == 3) ){
			visit[ny][nx] = 1;
			dfs(ny, nx);
			visit[ny][nx] = 0;
		}
	}
}


int main() {
//	freopen("input.txt", "r", stdin);
	for (int tc = 1; tc<= 10; ++tc) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		ans = 0;
		input();
	//	printMap();
		visit[1][1] = 1;
		dfs(1, 1);
		printf("#%d %d\n", tc, ans);
	}
//	fclose(stdin);

	return 0;
}
