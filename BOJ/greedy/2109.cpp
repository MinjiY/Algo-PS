/*
    [BOJ] 2109 순회강연
    https://www.acmicpc.net/problem/2109
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector<pair<int, int>> v;
int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, ans = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int day, p;
		cin >> p >> day;
		v.push_back(make_pair(day, p));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		ans += v[i].second;					//강연료를 먼저 다 더함
		pq.push(v[i].second);				//강연료를 pq에 push

		if (pq.size() > v[i].first) {		//
			ans -= pq.top();
			pq.pop();
		}
	}

	cout << ans << "\n";

	return 0;
}