/*
	[BOJ] 11051 이항 계수 2
	https://www.acmicpc.net/problem/11051
*/
#include<iostream>
using namespace std;

int dp[1001][1001];
//이항계수[N_number][K_number] = 이항계수[N_number - 1][K_number-1] + 이항계수[N_number-1][K_number]

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j || j == 0) {
				dp[i][j] = 1;
			}
			else
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	cout << dp[n][k];
	return 0;
}