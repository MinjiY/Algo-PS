/*
    [BOJ] 15666 N과 M(12)
    https://www.acmicpc.net/problem/15666
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int cnt[8], num[8], arr[8];
vector<int> list;
void count() {
	int pre_number = arr[0];
	int count = 1;
	int indx = 0;

	for (int i = 1; i < N; ++i) {
		if (pre_number == arr[i])
			++count;
		else {
			cnt[indx] = count;
			num[indx] = pre_number;
			pre_number = arr[i];
			count = 1;
			indx += 1;
		}
	}
	cnt[indx] = count;
	num[indx] = pre_number;
	N = indx;
}
void bfs(int indx, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << list[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = indx; i <= N; ++i) {
		list.push_back(num[i]);
		bfs(i, depth + 1);
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

	count();
	bfs(0, 0);
	return 0;
}