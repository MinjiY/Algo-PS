/*
    [BOJ] 15654 N과 M(5)
    https://www.acmicpc.net/problem/15654
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[10000];
vector<int> list;
int visit[10000];
void bfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i) 
			cout << list[i] << " ";
		cout << "\n";
	}
	
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			list.push_back(arr[i]);
			bfs(cnt+1);
			list.pop_back();
			visit[i] = false;
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	bfs(0);
	return 0;
}