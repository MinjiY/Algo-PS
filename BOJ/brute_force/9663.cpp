/*
    [BOJ] 9663 N-Queen
    https://www.acmicpc.net/problem/9663
*/
#include <iostream>
using namespace std;
int vy[16];
int vx[16];
int N;

int dfs(int y, int x) {

	for (int i = 0; i < y; ++i) {
		if (y == vy[i] || x == vx[i]) return 0;	//가로세로 겹침
		if (abs(x - vx[i]) == abs(y - vy[i])) return 0;	//대각선 겹침

	}
	if (y == N - 1)return 1;

	vy[y] = y;
	vx[y] = x;

	int r = 0;
	for (int i = 0; i < N; ++i) {
		r += dfs(y + 1, i);
	}
	return r;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	int r = 0;
	for (int i = 0; i < N; ++i) {
		r += dfs(0, i);
	}
	cout << r << "\n";
	return 0;
}