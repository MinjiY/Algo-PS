/*
	[BOJ] 6603 ·Î¶Ç
	https://www.acmicpc.net/problem/6603
*/
#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

int k;
int arr[13];
int visit[13];
int selected[13];

void dfs(int indx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << arr[selected[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = indx; i < k; ++i) {
		if (visit[i] == 0) {
			visit[i] = 1;
			selected[cnt] = i;
			dfs(i + 1, cnt + 1);
			selected[cnt] = 0;
			visit[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; ++i) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << "\n";
	}
	return 0;
}