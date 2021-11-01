/*
	[BOJ] 2252 �� �����
	https://www.acmicpc.net/problem/2252
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;	// N���� �л�, M�� Ű�� ���� Ƚ��
vector<int> adj[32001];
int indeg[32001];

void topo_sort() {
	queue<int> q;
	vector<int> result;
	//indeg�� 0�� ������ ��� q�� �ִ´�.
	for (int i = 1; i <= N; ++i) {
		if (indeg[i] == 0) q.push(i);
	}
	while (!q.empty()){
		//q�� front�� �ִ� ������ �����ͼ� ���� ���� ����� �߰�
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		// �ش� �������κ��� ����� ��� ������ indeg ���� 1 ���ҽ�Ų��.
		// �̶� indeg�� 0�� �Ǿ��ٸ� �� ������ ť�� �߰��Ѵ�.
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			indeg[next]--;
			if (indeg[next] == 0) q.push(next);
		}
	}
	
	//�������� ����� �л����� ���� ���� �ʴٸ� ����Ŭ�� �����ϴ� ��
	if (result.size() != N) {
		cout << "cycle exists";
		return;
	}
	for (int i = 0; i < N; ++i)
		cout << result[i] << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	// A, B ������ ���� => �л� A�� �л� B�� �տ� ���� �Ѵ�
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
	}
	topo_sort();

	return 0;
}