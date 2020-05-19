/*
    [BOJ] 13023 ABCDE
    https://www.acmicpc.net/problem/13023
 */
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N, M;			//N:사람수, M: 친구 관계의 수

bool visit[2000] , result;
vector<int> V[2000];



void dfs(int idx, int cnt) {
	if (cnt == 5) {
		result = true;
		return;
	}
	visit[idx] = true;

	for (int i = 0; i < V[idx].size(); ++i)
	{
		int Next = V[idx][i];
		if (visit[Next] == true) continue;
		dfs(Next, cnt + 1);
		if (result == true) return;
	}
	visit[idx] = false;
}

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	for (int i = 0; i < N; ++i) {
		memset(visit, false, sizeof(visit));
		dfs(i, 1);
		if (result == true) break;
	}
	if (result == true) cout << "1" << "\n";
	else cout << "0" << "\n";


	return 0;
}