/*
	[BOJ] 1285 동전 뒤집기
	https://www.acmicpc.net/problem/1285
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

char flip(char x) {
	if (x == 'H') return 'T';
	else return 'H';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;

	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = n * n;

	for (int state = 0; state < (1 << n); state++) {		
		//cout << "state: " << state << "\n";
		int sum = 0;
		for (int j = 0; j < n; j++) {					//열
			int cnt = 0;
			for (int i = 0; i < n; i++) {				//행
				char cur = a[i][j];
		//		cout << " cur: " << cur << "  i , j:  " << i << "," << j << "\n";
				if (state & (1 << i)) {
					cur = flip(cur);
		//			cout << "i: " << i << "  1<<i: " << (1 << i)<<"\n";
				}
				if (cur == 'T') {
					cnt += 1;
		//			cout << "T\n";
				}
			}
			sum += min(cnt, n - cnt);
		}
		if (ans > sum) ans = sum;
	}
	cout << ans << "\n";
	return 0;
}

