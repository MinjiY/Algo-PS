/*
	[BOJ] 11404 �÷��̵�
	https://www.acmicpc.net/problem/11404
*/

#include <iostream>
using namespace std;

int map[105][105];
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = 0;	//������ ����
	int m = 0;	//������ ����
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fill(map[i], map[i] + 1 + n, INF);
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);	// �������� ���۵��ÿ� �������� ����뼱�� �ϳ��� �ƴ� �� �ִ�
	}
	for (int i = 1; i <= n; ++i) {
		map[i][i] = 0;					// �ڽų��� ����ġ0
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	// �� �� ���� ��� 0����,
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] == INF) cout << "0 ";
			else cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}