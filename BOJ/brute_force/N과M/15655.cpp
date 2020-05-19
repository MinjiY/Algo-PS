/*
    [BOJ] 15655 N과 M(6)
    https://www.acmicpc.net/problem/15655
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool visit[10000];
int arr[10000];

vector<int> list;

void bfs(int indx,int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = indx; i < N; ++i) {
		list.push_back(arr[i]);
		bfs(i+1, cnt + 1);
		list.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	
	bfs(0,0);
	return 0;
}