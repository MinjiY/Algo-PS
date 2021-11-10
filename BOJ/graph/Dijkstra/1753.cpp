/*
	[BOJ] 1753 최단경로
	https://www.acmicpc.net/problem/1753
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;	// 정점의 갯수, 간선의 갯수, 시작 정점
vector<pair<int, int>> adj[20002];
int dist[20002];
int visit[20002];

struct compare {
	bool operator() (pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

void dijkstra(int start ) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
	pq.push(make_pair(start,0));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first;
		pq.pop();

		if (visit[cur] == 1) {
			continue;
		}
		visit[cur] = 1;

		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].first;
			int next_w = adj[cur][i].second;

			if (dist[next] > (dist[cur] + next_w)) {
				dist[next] = dist[cur] + next_w;
				pq.push(make_pair(next, dist[next]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> V >> E >> K;
	for (int i = 1; i <= E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; ++i) {
		dist[i] = 1e9;
	}
	
	dijkstra(K);
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == 1e9) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}