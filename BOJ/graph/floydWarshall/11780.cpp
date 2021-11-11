/*
	[BOJ] 11780 플로이드 2
	https://www.acmicpc.net/problem/11780
	
	A에서 B로 가는데 드는 최소비용
*/

#include <iostream>
#include <vector>
using namespace std;

int map[105][105];
int nxt[105][105];
const int INF = 1e9;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	// 충분히 큰 값으로 채움
	for (int i = 1; i <= n; ++i) {
		fill(map[i], map[i] + 1 + n, INF);
	}


	for (int k = 0; k < m; ++k) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
		nxt[a][b] = b;
	}
	for (int i = 1; i <= n; ++i) {
		map[i][i] = 0;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] == INF) cout << "0 ";
			else cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (nxt[i][j] == 0 || map[i][j] == INF) {
				cout << "0\n";
				continue;
			}
			vector<int> path;
			int st = i;
			while (st != j) {
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << " ";
			for (auto x : path) cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}