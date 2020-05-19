/*
    [BOJ] 16940 BFS 스페셜 저지
    https://www.acmicpc.net/problem/16940
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
vector<int> adj [100001];
queue<int> q;
int visit[100001];

int input[100001];
int input_index[100001];

int dist[100001];
int parent[100001];

void print() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//input
	cin >> N;

	for (int k = 1; k <= N - 1; ++k) {
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for (int k = 1; k <= N; ++k) {
		int x;
		cin >> x;
		input[k] = x;
		input_index[x] = k;
	}

	int start = 1;
	visit[start] = 1;
	dist[start] = 0;
	parent[start] = 0;
	q.push(1);


	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		
		for (int i = 0; i < adj[temp].size(); ++i) {
			int next = adj[temp][i];
			if (!visit[next]) {
				visit[next] = 1;
				dist[next] = dist[temp] + 1;
				parent[next] = temp;
				q.push(next);
			}
		}
	}
	for (int k = 1; k <= N-1; ++k) {
		if (dist[input[k]] > dist[input[k + 1]] ||
			input_index[parent[input[k]]] > input_index[parent[input[k + 1]]]) {
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << 1 << "\n";
    
    return 0;
}