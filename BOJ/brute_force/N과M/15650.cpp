/*
    [BOJ] 15650 N과 M(2)
    https://www.acmicpc.net/problem/15650
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;			//1<= M <= N <= 8
					//N: range, M: number of output
vector<int> list;

void dfs(int indx,int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << list[i] + 1 << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = indx; i < N; i++) {
		list.push_back(i);
		dfs(i+1,cnt + 1);
		list.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	dfs(0,0);
	return 0;
}