/*
    [BOJ] 2529 부등호
    https://www.acmicpc.net/problem/2529
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int K;
char str[11];
int small[11];
int big[11];

bool check(int* arr) {
	for (int i = 0; i < K; ++i) {
		if ( str[i] == '<' && arr[i] > arr[i+1] ) {
			return false;
		}
		if (str[i] == '>' && arr[i] < arr[i + 1])
		{
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> str[i];
	}
	int cnt = 0;
	for (int i = 0; i < K + 1; ++i) {
		small[i] = cnt++;
	}
	cnt = 9;
	for (int i = 0; i < K + 1; ++i) {
		big[i] = cnt--;
	}

	do {
		if (check(big)) {
			break;
		}
	} while (prev_permutation(big, big+(K+1)));
	
	do {
		if (check(small)) {
			break;

		}
	} while (next_permutation(small, small+(K+1)));

	for (int i = 0; i < K + 1; ++i) {
		cout << big[i];
	}
	cout << "\n";
	for (int i = 0; i < K + 1; ++i) {
		cout << small[i];
	}
	cout << "\n";

	return 0;
}
