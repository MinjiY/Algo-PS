/*
    [BOJ] 11559 Puyo Puyo
    https://www.acmicpc.net/problem/11559
 */
// BFS , DFS, simulation
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef struct {
	int number, cnt;
}NODE;

char map[13][7];
NODE number[13][7];
bool visit[13][7];
int gravity_check[6];
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
void input() {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			scanf(" %c", &map[i][j]);
		}
	}
}
void printMap() {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printNumber() {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			printf("%d %d  ", number[i][j].number, number[i][j].cnt);
		}
		printf("\n");
	}
	printf("\n");
}
void bfs_numbering(int y, int x, int num, char alphabet) {
	int puyo_cnt = 1;
	queue<pair<int, int>> q;
	visit[y][x] = 1;

	pair<int, int> temp;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (visit[ny][nx] == 1 || ny < 0 || nx < 0 || ny >= 12 || nx >= 6) {
				continue;
			}

			if (map[ny][nx] == alphabet) {
				visit[ny][nx] = 1;
				number[ny][nx].number = num;
				number[ny][nx].cnt = puyo_cnt++;

				q.push(make_pair(ny, nx));
			}

		}
	}
}
void combo_func(int num) {

	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (number[i][j].number == num) {
				map[i][j] = '.';
			}
		}
	}
}
int main() {
	int combo = 0;
	int ON_OFF = 1;
	input();
	//	printMap();
	while (ON_OFF) {
		bool flag = true;
		memset(number, 0, sizeof(number));
		memset(visit, 0, sizeof(visit));
		memset(gravity_check, 0, sizeof(gravity_check));
		int numbering = 1;
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (map[i][j] != '.' && visit[i][j] == 0) {
					flag = false;
					number[i][j].number = numbering;
					bfs_numbering(i, j, numbering, map[i][j]);
					numbering++;
				}
			}
		}
		if (flag)
			break;
	//	printNumber();
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (number[i][j].cnt >= 3) {
					flag = true;
					combo_func(number[i][j].number);
				}
			}
		}
		if (flag) {
			combo++;
		}
		else {
			break;
		}
		//printMap();
		bool flag_g = true;
		for (int j = 0; j < 6; ++j) {
			int start = 0;
			for (int i = 11; i > 0; --i) {
				int swap_cnt = 0;

				if (map[i][j] == '.') {

					for (int k = i - 1; k >= 0; --k) {
						if (map[k][j] != '.') {
							map[i - (swap_cnt++)][j] = map[k][j];
							map[k][j] = '.';
							flag_g = false;
						}
					}
					break;
				}
			}
		}

	}
	printf("%d \n", combo);
	return 0;
}