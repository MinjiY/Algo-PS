#include <iostream>
#include <algorithm>
using namespace std;

int dp[100002];
int n;
int arr[100002];
int main() {
	int MAX = -9999999;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> dp[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (dp[i - 1] + dp[i] > 0 && dp[i-1]>0) {		//전체 합이 - 일 수 있음
			dp[i] = dp[i - 1] + dp[i];
		}

		if (MAX < dp[i] ) {
			MAX = dp[i];
		}
	}

	cout << MAX << "\n";
	return 0;
}
