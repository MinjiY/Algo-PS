/*
    [BOJ] 1967 트리의 지름
    https://www.acmicpc.net/problem/1967
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int visit[100001];
int diameter;
int farthestNode = 0;

vector<pair<int, int>> graph[100001];

void dfs(int node, int cost) {

	if (visit[node])			//이미 방문한 곳
		return;

	visit[node] = 1;

	if (diameter < cost) {
		diameter = cost;
		farthestNode = node;
	}
	for (int i = 0; i < graph[node].size(); ++i) {
		dfs(graph[node][i].first, cost + graph[node][i].second);
	}

}

int main() {
	cin >> N;

	for (int i = 1; i < N; ++i) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;

		graph[node1].push_back(make_pair(node2, cost));
		graph[node2].push_back(make_pair(node1, cost));
	}
	memset(visit, 0, sizeof(visit));

	//루트에서 가장 먼 정점
	dfs(1, 0);

	//해당 정점에서 가장 먼 정점까지의 거리가 트리 지름
	memset(visit, 0, sizeof(visit));
	diameter = 0;
	dfs(farthestNode, 0);

	cout << diameter << "\n";

	return 0;
}