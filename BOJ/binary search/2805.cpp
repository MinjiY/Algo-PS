/*
	[BOJ] 2805 나무 자르기
	https://www.acmicpc.net/problem/2805
*/
#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

long long tree[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long N = 0;
	long long M = 0;
	long long max = 0;
	long long left, right;
	long long result = 0;

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> tree[i];
		if (max < tree[i])
			max = tree[i];
	}
	left = 0; right = max;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long total = 0;

		for (int i = 0; i < N; ++i)
			if (mid < tree[i])
				total += tree[i] - mid;

		if (total >= M) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << "\n";
	return 0;
}