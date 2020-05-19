/*
    [BOJ] 15663 N과 M(9)
    https://www.acmicpc.net/problem/15663
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[8], cnt[8], num[8];

vector<int> list;

void count() {
	int pre_number = arr[0];
	int counts = 1;
	int indx = 0;
	
	for(int i=1; i<N; i++){
		if (pre_number == arr[i])
			counts += 1;
		else {
			cnt[indx] = counts;
			num[indx] = pre_number;
			counts = 1;
			pre_number = arr[i];
			indx += 1;
		}
	}
	cnt[indx] = counts;
	num[indx] = pre_number;
	N = indx;
}

void bfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << list[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i <= N; ++i) {
		if (cnt[i]) {
			cnt[i] -= 1;
			list.push_back(num[i]);
			bfs(depth + 1);
			list.pop_back();
			cnt[i] += 1;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	count();
	bfs(0);
	return 0;
}