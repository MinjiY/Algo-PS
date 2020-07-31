/*
	[BOJ] 11050 이항 계수 1
	https://www.acmicpc.net/problem/11050
*/
#include <iostream>
using namespace std;

int Factorial(int num) {
	if (num == 1 || num == 0) {
		return 1;
	}
	return (Factorial(num - 1) * num);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	cout << Factorial(n) / (Factorial(k) * Factorial(n - k));
	return 0;
}