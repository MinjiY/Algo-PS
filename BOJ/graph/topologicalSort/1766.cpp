/*
	[BOJ] 1766 ������
	https://www.acmicpc.net/problem/1766

	1. N���� ������ ��� Ǯ����Ѵ�.
	2. ���� Ǫ�� ���� ���� ������ �ִ� ������, ���� Ǫ�� ���� ���� ������ �ݵ�� ���� Ǭ��.
	3. �����ϸ� ���� �������� Ǯ����Ѵ�.
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
		// �տ� �ü� �ִ°� (���� ���� ��� ����� ����)
		int cur = pq.top(); 
		pq.pop();
		result.push_back(cur);		// ����� �߰�
		
		// �ش� �������κ��� ����� ��� ������ indegree ����
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