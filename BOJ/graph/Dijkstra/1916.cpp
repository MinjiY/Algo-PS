/*
	[BOJ] 1916 최소비용 구하기
	https://www.acmicpc.net/problem/1916

	N개의도시
	A번째 도시에서 B번째 도시 가는데 드는 버스 비용을 최소화
	
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;	//도시의 갯수, 버스의 갯수
vector<pair<int, int>> adj[1002];
int visit[1002];
int dist[1002];

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>  pq;
	pq.push(make_pair(start, 0));
	dist[start] = 0;

	while (!pq.empty()) {
		int node = pq.top().first;
		int w = pq.top().second;
		pq.pop();

		/*
			1 2 10
			1 2 2 
			같은 경로에 대해 가중치가 다른 경우 처리
		*/
		if (dist[node] < w) continue;

		for (int i = 0; i < adj[node].size(); ++i) {
			int next = adj[node][i].first;
			int next_w = adj[node][i].second;

			if (dist[next] > (dist[node] + next_w) ) {
				dist[next] = (dist[node] + next_w);
				pq.push(make_pair(next, next_w));
			}
		}
	}
	

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	int start, end;
	cin >> start >> end;
	for (int i = 0; i <= N; ++i) {
		dist[i] = 1e9;
	}
	dijkstra(start);
	cout << dist[end] << "\n";

	return 0;
}