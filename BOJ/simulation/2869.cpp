/*
	[BOJ] 2980 달팽이는 올라가고 싶다
	https://www.acmicpc.net/problem/2869
*/
#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

long long a, b, v;
int main() {
	// 5 - 2 / 2 - 1  => 2 - 1 (1) 2 -1 (2) 2 - 1(3) 2-1 (4) 
	//						1		2		 3			4
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b >> v;
	long long ans = (v-a) / (a-b);
	if (ans * (a - b) >= (v - a))		//
	{
		cout << ans + 1 << "\n";
	}
	else {								//
		cout << ans + 2 << "\n";
	}
	return 0;
}