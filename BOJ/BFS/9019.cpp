/*
    [BOJ] 9019 DSLR
    https://www.acmicpc.net/problem/9019
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//벡터 => 배열
int T;
bool visit[10000];

int command_D(int str) {
	//cout << temp << "\n";
	str = (2 * str) % 10000;
	return str;
}
int command_S(int str) {
	//cout << temp << "\n";
	if (str == 0) {
		str = 9999;
	}
	else {
		str -= 1;
	}
	return str;
}
int command_L(int str) {
	int d1 = (str / 1000);
	str = str % 1000;
	int d2 = (str / 100) * 1000;
	str = str % 100;
	int d3 = (str / 10) * 100;
	str = str % 10;
	int d4 = str * 10;
	return d1 + d2 + d3 + d4;
}
int command_R(int str) {
	int d1 = str % 10;
	d1 *= 1000;
	int d4 = (str / 1000) * 100;
	str = str % 1000;
	int d3 = (str / 100) * 10;
	str = str % 100;
	int d2 = (str / 10);

	return d1+d2+d3+d4;
}

void bfs(int str1, int str2) {
	queue<pair<int, string>> q;
	visit[str1] = true;
	q.push(make_pair(str1, ""));
	while (!q.empty()) {
		int temp = q.front().first;
		string ans = q.front().second;
		q.pop();

		if (temp == str2) {
			cout << ans<<"\n";
			return;
		}

		int D = command_D(temp);
		//	cout << D << "\n";
		
		
		if (!visit[D]) {
			q.push(make_pair(D, ans+'D'));
			visit[D] = true;
		}

		int S = command_S(temp);
		//	cout << S << "\n";
		if (!visit[S]) {
			q.push(make_pair(S, ans + 'S'));
			visit[S] = true;
		}
		int L = command_L(temp);
		if (!visit[L]) {
			q.push(make_pair(L, ans+'L'));
			visit[L] = true;
		}
		
		int R = command_R(temp);
		if (!visit[R]) {
			q.push(make_pair(R, ans+'R'));
			visit[R] = true;
		}

	}
	//	cout << "q가 빈거\n";

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int str1;
	int str2;

	cin >> T;
	while (T--) {
		cin >> str1 >> str2;
		bfs(str1, str2);
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}