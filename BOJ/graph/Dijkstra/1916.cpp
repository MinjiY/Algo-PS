/*
	[BOJ] 1916 �ּҺ�� ���ϱ�
	https://www.acmicpc.net/problem/1916

	N���ǵ���
	A��° ���ÿ��� B��° ���� ���µ� ��� ���� ����� �ּ�ȭ
	
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;	//������ ����, ������ ����
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
			���� ��ο� ���� ����ġ�� �ٸ� ��� ó��
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