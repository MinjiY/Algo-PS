/*
    [BOJ] 11399 ATM
    https://www.acmicpc.net/problem/11399
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int P[1001];
	for (int i = 0; i < n; ++i) {
		cin >> P[i];
	}
	
	int ans = 0;
	int sum = 0;
	sort(P, P + n);
	for (int i = 0; i < n; ++i) {
		sum += P[i];
		ans += sum;
	}
	cout << ans << "\n";

	return 0;
}