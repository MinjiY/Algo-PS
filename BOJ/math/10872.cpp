/*
    [BOJ] 10872 팩토리얼
    https://www.acmicpc.net/problem/10872
 */
#include <iostream>
using namespace std;

//5! = 5*4*3*2*1

int factorial(int n) {
	int result = n;
	if (n == 0) {
		return 1;
	}
	n--;
	while (n >= 1) {
		result = result * n;
		n--;
	}
	return result;
}
int main() {
	
	int input = 0;
	cin >> input;

	cout << factorial(input) << "\n";

	return 0;
}