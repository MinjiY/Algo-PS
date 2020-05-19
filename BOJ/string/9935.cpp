/*
    [BOJ] 9935 문자열 폭발
    https://www.acmicpc.net/problem/9935
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	bool flag = false;
	string str, bomb;
	cin >> str >> bomb;
	
	char result[1000001] = { 0 };
	int indx = 0;

	for (int i = 0; i < str.size(); ++i) {
		result[indx++] = str[i];

		if (result[indx - 1] == bomb[bomb.length() - 1]) {
			
			if (indx - bomb.length() < 0)
				continue;

			bool detected = true;
			for (int j = 0; j < bomb.length(); ++j) {
				if (result[indx - j - 1] != bomb[bomb.length() - 1 - j]) {
					detected = false;
					break;
				}
			}

			if (detected)
				indx -= bomb.length();

		}

	}

	if (!indx) {
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