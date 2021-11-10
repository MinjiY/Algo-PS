/*
	[BOJ] 11779 최소비용 구하기2
	https://www.acmicpc.net/problem/11779
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M; // 도시의 갯수, 버스의 갯수

vector<pair<long long, int>> adj[1004];	//가중치, 노드
int dist[1004];
int route[1004];
vector<int> route_v;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;	
	
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int w = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 계산된 가중치값이 현재의 가중치보다 작으면 패스 => 안하면 시간초과
		if (dist[cur] < w) continue;

		for (int i = 0; i < adj[cur].size(); ++i) {
			int next_w = adj[cur][i].first;
			int next = adj[cur][i].second;

			if (dist[next] > dist[cur] + next_w) {
				dist[next] = dist[cur] + next_w;
				route[next] = cur;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v;
		int w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	for (int i = 0; i <= N; ++i) {
		dist[i] = 1e9;
	}
	int start, end;
	cin >> start >> end;

	dijkstra(start);

	int temp = end;
	while (temp) {
		route_v.push_back(temp);
		temp = route[temp];
	}
	cout << dist[end]<<"\n"<< route_v.size()<<"\n";
	for (int i = route_v.size() - 1; i >= 0; --i) {
		cout << route_v[i] << " ";
	}
	
	return 0;
}