/*
	[BOJ] 2980 도로와 신호등
	https://www.acmicpc.net/problem/2980
*/

#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
int N, L;	//신호등 갯수, 도로의 길이
pair<int, int> arr[1001];	//R,G
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		int d, r, g;
		cin >> d >> r >> g;
		arr[d].first = r;
		arr[d].second = g;
	}

	int t = 1;				//전체 시간
	int m = 1;
	while (m < L) {
		if (arr[m].first != 0 && arr[m].second != 0) {
			if ((t % (arr[m].first + arr[m].second)) <= arr[m].first)	//빨간불
			{
				t += (arr[m].first - (t % (arr[m].first + arr[m].second)));
			}
		}
		t++;
		m++;
	}
	cout << t << "\n";
	return 0;
}