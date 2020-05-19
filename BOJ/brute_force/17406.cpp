/*
    [BOJ] 17406 배열 돌리기 4
    https://www.acmicpc.net/problem/17406
 */
#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
	int y, x, s;
}NODE;
int N, M, K;
int map[51][51];
int temp_map[51][51];
int original_map[51][51];

int selected[10];
NODE permutation[10];
int visit[10];
int sum[51];
int Min = 1e9;

void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void cp_map() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			map[i][j] = original_map[i][j];
			temp_map[i][j] = original_map[i][j];
		}
	}
}
void update_map() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			temp_map[i][j]= map[i][j] ;
		}
	}
}

void c_sum() {
//	cout << "sum하기전\n";
//	printMap();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			sum[i] += map[i][j];
		}
	}
	
	for (int i = 0; i < N; ++i) {
		if (Min > sum[i])
			Min = sum[i];
	}
	memset(sum, 0, sizeof(sum));
}
void rotate(int r, int c, int s) {		//한바퀴용
	int y = r - s;
	int x = c - s;
	int y_e = r + s;
	int x_e = c + s;

//	cout << y << " " << x << " " << y_e << " " << x_e<<"\n";
	
	for (int j = x+1; j <= x_e; ++j) {		//윗변
		map[y][j] = temp_map[y][j - 1];
	}
	for (int i = y + 1; i <= y_e; ++i) {
		map[i][x_e] = temp_map[i - 1][x_e];
	}
	for (int j = x_e - 1; j >= x; --j) {
		map[y_e][j] = temp_map[y_e][j + 1];
	}
	for (int i = y_e - 1; i >= y; --i) {
		map[i][x] = temp_map[i + 1][x];
	}

}
void solution() {

	for (int indx = 0; indx < K; ++indx) {
		int y = permutation[selected[indx]].y;
		int x = permutation[selected[indx]].x;
		int s = permutation[selected[indx]].s;
		int rot_num = s;
		while (rot_num) {
			rotate(y, x, rot_num);
			rot_num--;
			update_map();			//map => temp_map;
		}
	}
	c_sum();
}
void dfs(int cnt) {
	if (cnt == K) {
		solution();
		cp_map();
		return;
	}
	
	for (int i = 0; i < K; ++i) {
		if (visit[i] == 0) {
			visit[i] = 1;
			selected[cnt] = i;
			dfs(cnt + 1);
			selected[cnt] = 0;
			visit[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			temp_map[i][j] = map[i][j];
			original_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		cin >> permutation[i].y >> permutation[i].x >> permutation[i].s;
	}
//	printMap();
	for (int i = 0; i < K; ++i) {
		permutation[i].y--;
		permutation[i].x--;
	}

	dfs(0);

	cout << Min << "\n";


	return 0;
}
