/*
    [BOJ] 9613 GCD 합
    https://www.acmicpc.net/problem/9613
*/
#include <iostream>
#include <cstring>
using namespace std;

int list[101];
int T;
int N;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
        memset(list,0,sizeof(list));
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> list[i];
		}
		long long result = 0;
		for (int i = 0; i < N-1; ++i) {
			for (int j = i+1; j < N; ++j) {
				if (i == j) continue;
				result += gcd(list[i], list[j]);
			}
		}
		cout << result<<"\n";
		
	}

	return 0;
}
