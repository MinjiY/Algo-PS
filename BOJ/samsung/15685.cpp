/*
    [BOJ] 15685 드래곤 커브
    https://www.acmicpc.net/problem/15685
 */
#include <iostream>
#include <vector>
using namespace std;

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int N;
int map[101][101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans = 0;
	cin >> N;
	while (N--) {
		vector<int> curve;

		int x, y, d, g;
		cin >> x >> y >> d >> g;

		curve.push_back(d);
		map[y][x] = 1;

		for (int i = 0; i < g; ++i) {
			int s = curve.size();
			for (int k = s - 1; k >= 0; --k) {
				curve.push_back((curve[k] + 1) % 4);
			}
		}
		
		for (int i = 0; i < curve.size(); ++i) {
			y += dy[curve[i]];
			x += dx[curve[i]];
			if (x < 0 || y < 0 || x >= 101 || y >= 101) {
				continue;
			}
			map[y][x] = 1;
		}
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}