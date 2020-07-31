/*
	[BOJ] 5585 °Å½º¸§µ·
	https://www.acmicpc.net/problem/5585
*/
#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	N = 1000 - N;
	int ans = 0;
	while ( (N - 500) >= 0) {
		N = N - 500;
		ans++;
	}
	while ((N - 100) >= 0) {
		int q = N / 100;
		N = N-(100 * q);
		ans += q;
	}
	while ((N - 50) >= 0) {
		int q = N / 50;
		N = N - (50 * q);
		ans += q;
	}
	while ((N - 10) >= 0) {
		int q = N / 10;
		N = N - (10 * q);
		ans += q;
	}
	while ((N - 5) >= 0) {
		int q = N / 5;
		N = N - (5 * q);
		ans += q;
	}
	while ((N - 1) >= 0) {
		ans += N;
		N = 0;
	}
	cout << ans << "\n";
	return 0;
}