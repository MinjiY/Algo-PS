/*
	[BOJ] 1197 최소 스패닝 트리
	https://www.acmicpc.net/problem/1197
*/
#pragma warning (disable: 4996)
//Kruskal
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int v, e,ans,cnt;
pair<int, pair<int, int> > edge[100005];

int parent[100005];
int height[100005];

//union-find 
int find(int v) {
	if (v == parent[v])
		return v;
	else {
		int u = find(parent[v]);
		parent[v] = u;
		return u;
	}
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;			//같은 그룹

	if (height[u] > height[v])
		swap(u, v);
	parent[u] = v;
	if (height[u] == height[v]) ++height[v];
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> v >> e;			//정점의 갯수, 간선의 갯수
	for (int i = 0; i < e; ++i) {
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
	}
	
	for (int i = 1; i <= v; ++i) {		//초기화
		parent[i] = i;
		height[i] = 1;
	}
	sort(edge, edge + e);
	for (int i = 0; i < e; ++i) {
		int cost = edge[i].first;
		int v1 = edge[i].second.first;
		int v2 = edge[i].second.second;

		if (!is_diff_group(v1, v2)) continue;				//같은 그룹이면 0
		ans += cost;
		cnt++;
		
		if (cnt == v - 1) break;
	}
	cout << ans << "\n";

	return 0;
}
*/

//prim
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int v, e, ans, cnt;
typedef tuple<int, int, int> t3;
vector<pair<int, int>> adj[100005];
bool check[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	
	priority_queue<t3, vector<t3>, greater<t3>> pq;
	for (int nxt = 0; nxt < adj[1].size(); ++nxt) {
		pq.push({ adj[1][nxt].first,1,adj[1][nxt].second });
	}
	check[1] = 1;	//true

	while (1) {
		int cost, v1, v2;
		tie(cost, v1, v2) = pq.top();
		pq.pop();
		if (check[v2]) continue;
		check[v2] = 1;
		ans += cost;
		cnt++;
		if (cnt == v - 1) break;
		for (int nxt = 0; nxt < adj[v2].size(); ++nxt) {
			if (!check[adj[v2][nxt].second])
				pq.push({ adj[v2][nxt].first,v2,adj[v2][nxt].second });
		}
	}
	cout << ans << "\n";

	return 0;
}