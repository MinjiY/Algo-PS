/*
    [BOJ] 15652 N과 M(4)
    https://www.acmicpc.net/problem/15652
 */
#include <iostream>
//#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> list;
void dfs(int indx,int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i)
			cout << list[i] + 1 << " ";
		cout << "\n";
		return;
	}

	for (int i = indx; i < N; ++i) {
		list.push_back(i);
		dfs(i , cnt + 1);
		list.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	dfs(0, 0);
	return 0;
}