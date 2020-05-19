/*
    [BOJ] 10808 알파벳 개수
    https://www.acmicpc.net/problem/10808
 */
#include <iostream>
using namespace std;

string str;
int list[26];
// a: 97 ~ z: 122
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;
	
	for (int i = 0;i<str.length()+1; ++i) {
		list[str[i] - 97]++;
	}
	for (int i = 0; i< 26; ++i) {
		cout << list[i] << " ";
	}
	

	return 0;
}
