/*
    [BOJ] 2210 숫자판 점프
    https://www.acmicpc.net/problem/2210
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int map[5][5];
const int dy[] = { 0,0,1,-1 };
const int dx[] = { -1,1,0,0 };

vector<int> ans;
bool visit[1000000];
void dfs(int depth, int y, int x, int sum) {
	if (depth == 5) {
	//	if (find(ans.begin(), ans.end(), sum) == ans.end()) {
	//		ans.push_back(sum);
	//	}
		if (!visit[sum]) {
			visit[sum] = true;
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
			continue;
		
		dfs(depth + 1, ny, nx, sum*10+map[ny][nx]);

	}


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			dfs(0, i, j, map[i][j]);
		}
	}
	
	//cout << ans.size()<<"\n";
	int cnt = 0;
	for (int i = 0; i < 1000000; ++i) {
		if (visit[i]) {
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}