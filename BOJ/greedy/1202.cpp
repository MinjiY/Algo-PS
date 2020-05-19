/*
    [BOJ] 1202 보석 도둑
    https://www.acmicpc.net/problem/1202
 */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, k;
pair<int, int> jew[300001];	//무게 가격
int bag[300001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	priority_queue<int> pq;
	long long sum = 0;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> jew[i].first >> jew[i].second;
 	}
	for (int i = 0; i < k; ++i) {
		cin >> bag[i];
	}
	sort(jew, jew + n);
	sort(bag, bag + k);
	int indx = 0;
	for (int i = 0; i < k; ++i) {
		
		while (indx < n && jew[indx].first <= bag[i]) {
			pq.push(jew[indx].second);
			indx++;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum << "\n";
	return 0;
}