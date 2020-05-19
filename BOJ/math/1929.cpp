/*
    [BOJ] 1929 소수 구하기
 */
#include <iostream>
using namespace std;

bool check[1000001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a, b;
	cin >> a >> b;
	for (int i = 2; i < b; i++) {
		for (int j = i + i; j <= b; j += i) {
			check[j] = 1;
		}
	}
	for (int i = a; i <= b; ++i) {
        if (i == 1) continue;
		if (check[i] == 0) {
			cout << i<<"\n";
		}
	}

	return 0;
}