/*
	[BOJ] 17608 ¸·´ë±â
	https://www.acmicpc.net/problem/17608
*/
#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

int arr[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int MAX = 0; int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; --i) {
		if (MAX < arr[i]) {
			MAX = arr[i];
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}