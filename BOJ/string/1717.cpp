/*
    [BOJ] 1717 집합의 표현
    https://www.acmicpc.net/problem/1717
*/
//union-find (disjoint-set)
#include <iostream>
using namespace std;

int n, m;
int parent[1000002];
int height[1000002];

int find(int u) {
	if (u == parent[u]) {			//자기 자신을 가리키는 노드 = root
		return u;
	}
	else {
		int v = find(parent[u]);	//루트를 찾고
		parent[u] = v;				//u의 부모로 바꿈
		return v;
	}
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;				//루트가 같으면 == 같은 합집합 내에 있으면

	if (height[u] > height[v]) {	//트리의 높이가 더 높은게 부모가됨
		parent[v] = u;
		height[u] += height[v];
	}
	else {
		parent[u] = v;
		height[v] += height[u];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; ++i) {	//트리의 높이를 1로 초기화
		height[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int com, a, b;
		cin >> com >> a >> b;

		if (com == 0) {				//두 집합을 합침
			merge(a, b);
		}
		else if (com == 1) {		//두 원소가 같은 집합에 포함되어있는지 확인
			int x = find(a);
			int y = find(b);
			if (x == y) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}