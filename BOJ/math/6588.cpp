/*
    [BOJ] 6588 골드바흐의 추측
    https://www.acmicpc.net/problem/6588
*/

#include <iostream>
using namespace std;

#define MAX 1000000
bool check[MAX];
void prime() {
	for (int i = 2; i*i < MAX; ++i) {
		if (!check[i]) {
			for (int j = i * i; j < MAX; j += i) {
				check[j] = 1;
			}
		}
	}
	check[1] = 1;
}
void solution(int input) {
	int i, j, mid = input>>1;
	for (i = 0,j=input; i <= mid; ++i,--j) {
		if ( (!check[j]) && (!check[i])&& (i%2==1) && (j%2 == 1)  ) {
			cout << input << " = " << i << " + " << j << "\n";
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int input= 0,a=0,b=0;
	prime();
	while (1) {
		cin >> input;
		if (!input) break;
		//solution
		solution(input);
	}
	return 0;
}