/*
	[BOJ] 2252 줄 세우기
	https://www.acmicpc.net/problem/2252
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;	// N명의 학생, M은 키를 비교한 횟수
vector<int> adj[32001];
int indeg[32001];

void topo_sort() {
	queue<int> q;
	vector<int> result;
	//indeg가 0인 정점을 모두 q에 넣는다.
	for (int i = 1; i <= N; ++i) {
		if (indeg[i] == 0) q.push(i);
	}
	while (!q.empty()){
		//q의 front에 있는 정점을 가져와서 위상 정렬 결과에 추가
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		// 해당 정점으로부터 연결된 모든 정점의 indeg 값을 1 감소시킨다.
		// 이때 indeg가 0이 되었다면 그 정점을 큐에 추가한다.
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			indeg[next]--;
			if (indeg[next] == 0) q.push(next);
		}
	}
	
	//위상정렬 결과가 학생들의 수와 같지 않다면 사이클이 존재하는 것
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
	// A, B 순서로 들어옴 => 학생 A가 학생 B의 앞에 서야 한다
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
	}
	topo_sort();

	return 0;
}