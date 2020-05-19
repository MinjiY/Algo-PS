/*
    [BOJ] 16947 서울 지하철 2호선
    https://www.acmicpc.net/problem/16947
 */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> adj[3001];
int selected[3001];
int start;
int ans[3001];
int visit[3001];
void dfs(int num, int cnt) {
	if (num == start && cnt >=2 && visit[num]) {
		selected[num] = 1;
		return;
	}
	visit[num] = 1;
	for (int j = 0; j < adj[num].size(); ++j) {
		int next = adj[num][j];
		if (visit[next]==false) {
			dfs(next, cnt+1);
		}
		else {
			if(next == start && cnt>=2)
				dfs(next, cnt);
		}
	}
}
void bfs(int num) {
	queue<pair<int,int>> q;
	visit[num] = 1;
	q.push(make_pair(num,0));
	while (!q.empty()) {
		int next = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (selected[next] == 1) {
			ans[num] = cnt;
			continue;
		}
		for (int i = 0; i < adj[next].size(); ++i) {
			if (visit[adj[next][i]] == 1)
				continue;
			
			visit[adj[next][i]] = 1;
			q.push(make_pair(adj[next][i], cnt + 1));	
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	for (int i = 1; i <= N; ++i) {
		if (selected[i] == 0) {
			start = i;
			dfs(i, 0);
			memset(visit, 0, sizeof(visit));
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (selected[i] == 0) {
			bfs(i);
			memset(visit, 0, sizeof(visit));
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}