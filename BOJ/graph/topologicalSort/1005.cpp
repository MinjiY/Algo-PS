/*
	[BOJ] 1005 ACM Craft
	https://www.acmicpc.net/problem/1005
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int T;
int N,K;
int dest;
int D[100005];		// 각 건물당 건설에 걸리는 시간 

int cache[100005];
vector<int> adj[100005];

int indeg[1005];

void topo_sort() {
	queue<int> q;
	
	for (int i = 1; i <= N; ++i) {
		if (indeg[i] == 0) {
			q.push(i);
			cache[i] = D[i];
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < adj[node].size(); ++i) {
			int next = adj[node][i];
			indeg[next]--;
			if (indeg[next] == 0) {
				q.push(next);
			}
			cache[next] = max(cache[next], cache[node] + D[next]);
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= K; ++i) {
			adj[i].clear();
		}
		memset(cache, 0, sizeof(cache));
		memset(indeg, 0, sizeof(indeg));
		cin >> N >> K;
		for (int i = 1; i <= N; ++i) {
			cin >> D[i];
		}
		for (int i = 1; i <= K; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			indeg[v]++;
		}
		cin >> dest;
		topo_sort();
		cout << cache[dest]<<"\n";
	}
	return 0;
}