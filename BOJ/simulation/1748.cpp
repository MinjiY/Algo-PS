/*
	[BOJ] 1748 수 이어 쓰기1
	https://www.acmicpc.net/problem/1748
*/

#pragma warning (disable: 4996)

#include <iostream>
#include <cmath>
using namespace std;
long long N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	long long num = 1;
	long long ans = 0;
	long long i = 0;
	for (; ; ++i) {
		int temp = pow(10, i);
		if ((N / temp) == 0) {
			break;
		}
	}
	for (int j = 0; j<i-1; ++j) {
		ans += ((9 * pow(10, j)) *(j+1));
	}
	num = pow(10,i-1);
	while (num <= N) {
		ans += i;
		num++;
	}
	cout << ans << "\n";
	return 0;
}
