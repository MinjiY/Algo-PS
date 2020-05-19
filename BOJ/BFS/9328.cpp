/*
    [BOJ] 9328 열쇠
    https://www.acmicpc.net/problem/9328
 */
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, M;
char complex[111][111];
int visit[111][111];
int doc;
bool key[26];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
void printMap() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			printf("%c", complex[i][j]);
		}
		printf("\n");
	}
}
void printKey() {
	char c = 'a';
	for (int i = 0; i < 26; ++i) {
		if (key[i] == true) {
			printf("%c ", c + i);
		}
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
void bfs(int y, int x) {
	visit[y][x] = 1;
	queue<pair<int, int>> q;
	queue < pair<int, int>> door[26];
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny > N+1 || nx >M+1)
				continue;
			if (visit[ny][nx] || complex[ny][nx] == '*')
				continue;
			
			visit[ny][nx] = 1;
			//printVisit();
			if ('A' <= complex[ny][nx] && complex[ny][nx] <= 'Z') {
				if ( key[complex[ny][nx] - 'A'] == true ) {
					q.push(make_pair(ny, nx));
				}
				else {
					door[complex[ny][nx] - 'A'].push(make_pair(ny, nx));
				}
			}
			else if ('a' <= complex[ny][nx] && complex[ny][nx] <= 'z') {
				q.push(make_pair(ny, nx));
				if ( key[complex[ny][nx] - 'a'] == false ) {
					key[complex[ny][nx] - 'a'] = true;
					
					while (!door[complex[ny][nx] - 'a'].empty()) {
						q.push(door[complex[ny][nx] - 'a'].front());
						door[complex[ny][nx] - 'a'].pop();
					}
				}

			}else {
				q.push(make_pair(ny, nx));
				if (complex[ny][nx] == '$') doc++;
			}
		}


	}

}
int main() {
	scanf("%d", &T);
	while (T--) {
		doc = 0;
		memset(visit, 0, sizeof(visit));
		memset(key, 0, sizeof(key));
		memset(complex, 0, sizeof(complex));
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				scanf(" %1c", &complex[i][j]);
			}
		}
		getchar();
		while (1) {
			char c;
			scanf("%1c", &c);
			if (c == '\n') {
				break;
			}
			else if (c == '0') {

			}
			else {
				key[c - 'a'] = true;
			}
		}
		//printMap();
		//printKey();

		bfs(0, 0);
		
		printf("%d\n", doc);
	}

	return 0;
}