/*
    [BOJ] 1676 팩토리얼 0의 개수
    https://www.acmicpc.net/problem/1676
 */

#include <iostream>
using namespace std;

//5! = 5*4*3*2*1
// 소인수 2와 5의 갯수에 의해 0의 갯수가 결정


int main() {
	int input;
	cin >> input;
	cout << (input / 5) + (input / 25) + (input / 125) << "\n";
    return 0;
}
