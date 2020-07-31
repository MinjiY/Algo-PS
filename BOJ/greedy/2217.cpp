#pragma warning (disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int lope[100001];
int ans ;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> lope[i];
	}
	sort(lope, lope + N);
	
	for (int i = 0; i < N; ++i) {
		if (ans < (lope[i] * (N - i))) {
			ans = (lope[i] * (N - i));
		}
	}
	cout << ans << "\n";

	return 0;
}