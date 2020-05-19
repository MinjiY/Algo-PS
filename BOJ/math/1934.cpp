/*
    [BOJ] 1934 최소공배수
    https://www.acmicpc.net/problem/1934
 */
#include <iostream>
using namespace std;
/*
int gcd(int a, int b) {
	if (!b)
		return a;
	else
		return gcd(b, a % b);
}*/
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, a,b;
	cin >> T;
	
	while (T) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
		T--;
	}
	return 0;
}
