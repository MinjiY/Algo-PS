/*
    [SWEA] 5356 의석이의 세로로 말해요
 */

#include <iostream> 
#include <string>

using namespace std;


int main() {

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		string str[5];
		int max_length = 0;

		// 입력
		for (int r = 0; r < 5; r++) {
			cin >> str[r];
			int length = str[r].size();
			if (max_length < length) { // 최대길이 update
				max_length = length;
			}
		}
		
		// 연산
		cout << "#" << i << " ";
		for (int c = 0; c < max_length; c++) {
			for (int r = 0; r < 5; r++) {
				if (str[r].size() > c) {
					cout << str[r][c];
				}
			}
		}
		cout << endl;
	}
	return 0;
}