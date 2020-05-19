/*
    [BOJ] 1991 트리 순회
    https://www.acmicpc.net/problem/1991
 */
#include <iostream>
#include <vector>
using namespace std;

// A:1 ~~~~
int N;
vector<pair<int, int>> adj[27];

void preorder(int node) {
	if (node == 0) {
		return;
	}
	cout << char(node+'A'-1);
	preorder(adj[node][0].first);
	preorder(adj[node][0].second);
	

}void inorder(int node) {
	if (node == 0) {
		return;
	}
	inorder(adj[node][0].first);
	cout << char(node + 'A' - 1);
	inorder(adj[node][0].second);
	
}void postorder(int node) {
	if (node == 0) {
		return;
	}
	postorder(adj[node][0].first);
	postorder(adj[node][0].second);
	cout << char(node + 'A' - 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		char root, node1, node2;
		cin >> root >> node1 >> node2;
		int node1c = 0;
		int node2c = 0;
		int rootc = root - 'A' + 1;
		if (node1 == '.') {
			node1c = 0;
		}
		else {
			node1c = node1 - 'A' + 1;
		}
		if (node2 == '.') {
			node2c = 0;
		}
		else {
			node2c = node2 - 'A' + 1;
		}

		adj[rootc].push_back(make_pair(node1c, node2c));

	}
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			cout << i<<" "<<adj[i][j].first << " "<<adj[i][j].second<<"\n";
		}
	}

	*/
	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);
	cout << "\n";
	return 0;
}