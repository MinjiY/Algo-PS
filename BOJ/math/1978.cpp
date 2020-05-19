/*
    [BOJ] 1978 소수 찾기
    https://www.acmicpc.net/problem/1978
 */
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, input,cnt =0;
	cin >> T;
	
	while (T--) {
		bool check = false;
		cin >> input;
		if (input == 1) continue;
		for (int i = 2; i <input; ++i) {
			if (input % i == 0) {
				check = true;
				break;
			}
		}
		if (!check)	cnt++;
	}
	cout << cnt;
	return 0;
}