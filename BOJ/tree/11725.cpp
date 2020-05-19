/*
    [BOJ] 11725 트리의 부모 찾기
    https://www.acmicpc.net/problem/11725
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> adj[100001];
queue<int> q;

int visit[100001];
int N;
int child[100001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	q.push(1);
	visit[1] = 1;
	
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < adj[temp].size(); ++i) {
			int next = adj[temp][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				child[next] = temp;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= N; ++i) {
		if (child[i]) {
			cout << child[i] << "\n";
		}
	}
	
	

	return 0;
}