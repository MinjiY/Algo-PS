/*
    [BOJ] 1212 8진수 2진수
    https://www.acmicpc.net/problem/1212
*/

#include <iostream>
using namespace std;

string str;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;

	if (str == "0") {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < str.size(); ++i) {
		switch (str[i] - '0') {
		case 0:
			cout << "000";
			break;
		case 1:
			if (i == 0) {
				cout << "1";
			}
			else {
				cout << "001";
			}
			break;
		case 2:
			if (i == 0) {
				cout << "10";
			}
			else {
				cout << "010";
			}
			break;
		case 3:
			if (i == 0) {
				cout << "11";
			}
			else {
				cout << "011";
			}
			break;
		case 4:
			cout << "100";
			break;
		case 5:
			cout << "101";
			break;
		case 6:
			cout << "110";
			break;
		case 7:
			cout << "111";
			break;
		}
	}
	

	return 0;
}