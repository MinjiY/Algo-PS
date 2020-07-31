/*
	[BOJ] 2750 수 정렬하기
	https://www.acmicpc.net/problem/2750
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n-1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << "\n";
	}
	return 0;
}