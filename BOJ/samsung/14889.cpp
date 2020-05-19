/*
    [BOJ] 14889 스타트와 링크
    https://www.acmicpc.net/problem/14889
 */
#include <iostream>
#include <cmath>
using namespace std;

int N;
int map[21][21];
bool selected[21];
int ans = 1e9;
	
void dfs(int start, int cnt) {
	if (cnt == N / 2) {
		int start=0, link=0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (selected[i] && selected[j]) start += map[i][j];
				if (!selected[i] && !selected[j]) link += map[i][j];
			}
		}
		int a = abs(start - link);
		if (ans > a) {
			ans = a;
		}
		return;
	}
	for (int i = start; i < N; ++i) {
		selected[i] = true;
		dfs(i + 1, cnt + 1);
		selected[i] = 0;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	dfs(1,0 );
	cout << ans << "\n";
	return 0;
}