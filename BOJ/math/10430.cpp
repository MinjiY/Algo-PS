/*
    [BOJ] 10430 나머지
    https://www.acmicpc.net/problem/10430
*/
#include <iostream>
using namespace std;
#define endl "\n"

int a, b, c;

int main() {
	cin >> a >> b >> c;
	
	cout << (a + b) % c << endl << (a % c + b % c) % c << endl << (a * b) % c << endl << (a % c * b % c) % c << endl;

	return 0;
}