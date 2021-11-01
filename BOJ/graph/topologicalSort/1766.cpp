/*
	[BOJ] 1766 문제집
	https://www.acmicpc.net/problem/1766

	1. N개의 문제는 모두 풀어야한다.
	2. 먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 반드시 먼저 푼다.
	3. 가능하면 쉬운 문제부터 풀어야한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int N, M;
vector<int> adj[32001];
int indeg[32001];


void topo_sort() {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> result;
	for (int i = 1; i <= N; ++i) {
		if (indeg[i] == 0) pq.push(i);
	}
	while (!pq.empty()) {
		// 앞에 올수 있는거 (위상 정렬 결과 만드는 과정)
		int cur = pq.top(); 
		pq.pop();
		result.push_back(cur);		// 결과로 추가
		
		// 해당 정점으로부터 연결된 모든 정점의 indegree 감소
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			indeg[next]--;
			if (indeg[next] == 0) pq.push(next);
		}
	}
	for (int i = 0; i < result.size(); ++i) cout << result[i] << " ";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); //u -> v
		indeg[v]++;
	}
	topo_sort();
	return 0;
}