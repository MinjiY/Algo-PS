/*
    [BOJ] 1373 2진수 8진수
    https://www.acmicpc.net/problem/1373
 */

#include <iostream>
using namespace std;
//아직미완
string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;
	int cnt = 0;
	int length =str.length();
	if ( length % 3) {
		length += 3 - (str.length() % 3);
	}

	for (int j = 0; j < (3 - (str.length() % 3)); ++j) {
		cnt++;
	}
	int result = 0;
	for (int i = 0; i < str.length(); ++i) {
			if (cnt % 3 == 0) {
				result += ((str[i] - 48) * 4);
				//printf("cnt: %d str[%d]: %d \n", cnt, i, str[i]-48);
			}
			else if (cnt % 3 == 1) {
				result += ((str[i] - 48) * 2);
				//printf("cnt: %d str[%d]: %d \n", cnt, i, str[i] - 48);
			}
			else if (cnt % 3 == 2) {
				result += ((str[i] - 48) * 1);
				//printf("cnt: %d str[%d]: %d \n", cnt, i, str[i] - 48);
			}

			++cnt;

			if (!(cnt % 3)) {
				cout << result;
				result = 0;
			}
	}
	cout << "\n";
	
	return 0;
}