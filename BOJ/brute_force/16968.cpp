/*
    [BOJ] 16968 차량 번호판 1
    https://www.acmicpc.net/problem/16968
 */
#include <iostream>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;
	int D = 10;
	int C = 26;
	int ans = 1;
	for (int i = 0; i < str.size(); ++i) {
		

		if (i  == 0) {
			if (str[i] == 'd') {
				ans = ans * D;
			}
			else {	//str[i] == 'c'
				ans = ans * C;
			}

		}
		else{				//i != 0
			if (str[i] == 'd') {
				if (str[i - 1] == 'd') {
					ans = ans * (D - 1);
				}
				else {
					ans = ans * D;
				}
			}
			else {	//str[i] == 'c'
				if (str[i - 1] == 'c') {
					ans = ans * (C - 1);
				}
				else {
					ans = ans * C;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}