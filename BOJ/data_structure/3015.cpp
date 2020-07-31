#pragma warning (disable: 4996)
/*
	[BOJ] 3015 오아시스 재결합
	https://www.acmicpc.net/problem/3015
*/

#include <iostream>
#include <stack>
using namespace std;

int N;
stack<pair<long long,long long> > s;

void print(stack<pair<long long, long long>> s2) {
	if (s2.empty()) {
		cout << "스택 비어있음\n";
	}
	while (!s2.empty()) {
		pair<long long, long long> p = s2.top();
		s2.pop();
		cout << p.first << " " << p.second << "\n";
	}
	return;
}
int main() {
	//freopen("patrik.in.1", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	long long result = 0;
	long long pa = 0;
	for (int i = 0; i < N; ++i) {
		
		long long h = 0;
		cin >> h;
		pair<long long, long long> p = { h,1 };		//높이, 쌍
		while (!s.empty() && s.top().first <= h ) {
			print(s);
			result += s.top().second;
			if (s.top().first == h) p.second += s.top().second;
			s.pop();
		}
		if (!s.empty()) {
			result++;		//스택은 안비어있는데 stack top보다는 작을때 4 1
		}
		s.push(p);
	}
	cout << result << "\n";

	//fclose(stdin);
	return 0;
}