/*
	[BOJ] 9935 문자열 폭발
	https://www.acmicpc.net/problem/9935
*/
#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

string str;
string er;
char result[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str >> er;
	int indx = 0;
	for (int i = 0; i < str.size(); ++i) {
		result[indx++] = str[i];

		if (result[indx - 1] == er[er.length() - 1]) {

			if (indx - er.length() < 0)
				continue;

			bool flag = true;
			for (int j = 0; j < er.size(); ++j) {
				if (result[indx - j - 1] != er[er.length() - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				indx -= er.length();
		}
	}
	if (!indx) {						//indx가 0
		cout << "FRULA\n";
	}
	else {
		for (int i = 0; i < indx; ++i) {
			cout << result[i];
		}
		cout << "\n";
	}
	return 0;
}
