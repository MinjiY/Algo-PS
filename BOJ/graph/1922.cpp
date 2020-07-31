#pragma warning (disable: 4996)
/*
	[BOJ] 1922 네트워크 연결
	https://www.acmicpc.net/problem/1922
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;	// 컴퓨터 수
int M;	// 간선 수
int p[1001];
int h[1001];
int ans, cnt;
pair<int, pair<int, int>> edge[100001];

int find(int v) {
	if (v == p[v])
		return v;
	else {
		int u = find(p[v]);
		p[v] = u;
		return u;
	}
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;

	if (h[u] > h[v])			//u의 높이가 더 높으면 
		swap(u, v);
	p[u] = v;
	if (h[u] == h[v]) ++h[v];
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
	}
	sort(edge, edge + M);
	for (int i = 1; i < N; ++i) {
		p[i] = i;
		h[i] = 1;
	}
	
	for (int i = 0; i < M; ++i) {
		int cost = edge[i].first;
		int v1 = edge[i].second.first;
		int v2 = edge[i].second.second;

		if (!merge(v1, v2)) continue;			//다른 그룹이면 1
		ans += cost;
		cnt++;
		if (cnt == N - 1) break;

	}
	cout << ans << "\n";
	return 0;
}