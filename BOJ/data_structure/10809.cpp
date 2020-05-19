/*
    [BOJ] 10809 알파벳 찾기
    https://www.acmicpc.net/problem/10809
 */
#include <iostream>
#include <vector>
using namespace std;

string str;
vector<int> list(26,-1);
// a: 97 ~ z: 122
//list = a b c d e f g h i ...
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;
	
	
	for (int i = 0; i < str.length(); ++i) {
		int index = str[i]- 97;
		if (list[index] < i&& list[index] != (-1) ) {
			continue;
		}
		list[index] = i;
	}
	for (int i = 0; i < 26; ++i) {
		cout << list[i] << " ";
	}
	return 0;
}