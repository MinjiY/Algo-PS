/*
    [BOJ] 2609 최대공약수와 최소공배수
    https://www.acmicpc.net/problem/2609
 */

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (!b)
		return a;
	else
		return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << "\n" << lcm(a, b) << "\n";
	
	return 0;
}