/*
    [BOJ] 3085 사탕 게임
    https://www.acmicpc.net/problem/3085
 */
#include <iostream>
#include <algorithm>
using namespace std;
int ans = 0;
int N;
char map[51][51];
void findeat() {
	int acnt = 0;
	int bcnt = 0;
	int res = 0;
	for (int i = 0; i < N; ++i) {
		acnt = 1; bcnt = 1, res = 0;;
		for (int j = 0; j < N-1; ++j) {
			if (map[i][j] == map[i][j + 1]) acnt++;
			else {
				if (acnt < res) {
					acnt = res;
				}
				acnt = 1;
			}
			if (map[j][i] == map[j + 1][i]) bcnt++;
			else {
				if (bcnt < res) {
					bcnt = res;
				}
				bcnt = 1;
			}
			if (acnt > bcnt) {
				res = acnt;
			}
			else {
				res = bcnt;
			}
			if (ans < res)
				ans = res;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N-1; ++j) {
			//가로
			swap(map[i][j], map[i][j + 1]);
			findeat();
			swap(map[i][j], map[i][j + 1]);

			swap(map[j][i], map[j + 1][i]);
			findeat();
			swap(map[j][i], map[j + 1][i]);

		}
	}

	cout << ans << "\n";
	return 0;
}