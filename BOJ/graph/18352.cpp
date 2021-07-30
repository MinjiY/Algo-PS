#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, X;
int visit[300001];
vector<int> adj[300001];
vector<int> result;

void bfs(int start) {
	queue<pair<int,int>> q;
	q.push(make_pair(start,0));
	visit[start] = 1;
	
	while (!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt == K) {
			result.push_back(node);
		}

		for (int i = 0; i < adj[node].size(); ++i) {
			int next = adj[node][i];
			if (!visit[next]) {
				visit[next] = 1;
				q.push(make_pair(next, cnt + 1));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	bfs(X);
	if (result.size() == 0) {
		cout << "-1\n";
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\n";
	}
	
	return 0;
}