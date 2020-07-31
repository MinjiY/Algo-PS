/*
	[BOJ] 12919 A와 B 2
	https://www.acmicpc.net/problem/12919
	출처: codeplus 강의
*/

#include <iostream>
#include <algorithm>
using namespace std;

string eraseEnd(string s) {
	s.pop_back();
	return s;
}
string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}
bool can(string s, string t) {
	if (s == t) return true;
	if (t.length() > 0) {
		if (t.back() == 'A' && can(s, eraseEnd(t))) {
			return true;
		}
		if (t[0] == 'B' && can(s, eraseEnd(rev(t)))) {
			return true;
		}
	}
	return false;
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << can(s, t) << "\n";
	return 0;
}