/*
    [BOJ] 1260 DFS와 BFS
    https://www.acmicpc.net/problem/1260
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, s;				//정점, 간선, 시작
vector<int> adj[10000];
int visit[10000];


void dfs(int index, int cnt) {
	cout << index<< " ";
	for (int i = 0; i < adj[index].size(); ++i) {
		int next = adj[index][i];
		if (visit[next] == true) continue;
		else{
			visit[next] = true;
			dfs(next,1);
		}
	}
}
void bfs(int index) {
	queue<int> q;
	q.push(index);
	while (!q.empty()) {
		index = q.front();
		q.pop();
		cout << index << " ";
		for (int i = 0; i < adj[index].size(); ++i) {
			int next = adj[index][i];
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> s;

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < M; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}
	visit[s] = 1;
	dfs(s, 0);
	memset(visit, 0, sizeof(visit));
	cout << "\n";
	visit[s] = 1;
	bfs(s);
	return 0;
}