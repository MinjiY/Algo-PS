/*
    [BOJ] 11724 연결 요소의 개수
    https://www.acmicpc.net/problem/11724
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;			//정점, 간선
bool visit[1001];
vector<int> adj[1001];
int check;

void dfs(int index) {
	//if (index == s && cnt == 1) {
	//	return;
	//}
	
	for (int i = 0; i < adj[index].size(); ++i) {
		int next = adj[index][i];
		if (visit[next] == false) {
			visit[next] = true;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i);
			cnt++;
		}
	}
	cout << cnt<<"\n";

	return 0;
}