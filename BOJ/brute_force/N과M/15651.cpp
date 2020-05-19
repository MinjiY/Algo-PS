/*
    [BOJ] 15651 N과 M(3)
    https://www.acmicpc.net/problem/15651
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;			//1<= M <= M <= 7
vector<int> list;

void dfs(int cnt) {
	if(cnt == M){
		for (int i = 0; i < M; ++i) {
			cout << list[i] + 1 << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		list.push_back(i);
		dfs(cnt+1);
		list.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	dfs(0);
	return 0;
}