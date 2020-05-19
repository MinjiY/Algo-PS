/*
    [BOJ] 2606 바이러스
    https://www.acmicpc.net/problem/2606
 */
//플로이드 와샬 알고리즘 => BFS로 풀었음
//+union-find로 풀림
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
int visit[101];
int N;
int cnt;
void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visit[cur] = 1;
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (int i = 0; i < adj[num].size(); ++i) {
			int next = adj[num][i];
			if (visit[next] == 1) continue;
			visit[next] = 1;
			cnt++;
	//		cout << next << "\n";
			q.push(next);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(1);
	cout << cnt << "\n";

	return 0;
}