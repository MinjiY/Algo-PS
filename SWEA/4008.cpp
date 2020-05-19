/*
    [SWEA] 4008 숫자 만들기
    모의 SW 역량테스트
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int op[11];
int num[12];
int selected[12];
int T, N;
int Max, Min;
int solution() {
	int first = num[0];
	for (int i = 0; i < N - 1; ++i) {
		switch (selected[i]) {
		case 0:
			first = first + num[i + 1];
			break;
		case 1:
			first = first - num[i + 1];
			break;
		case 2:
			first = first * num[i + 1];
			break;
		case 3:
			first = first / num[i + 1];
			break;
		}
	}
	return first;
}

void dfs(int cnt) {
	if (cnt == N - 1) {
		//for (int i = 0; i < N - 1; ++i) {
		//	cout << selected[i] << " ";
		//}
		//cout << "\n";
		int ans = solution();
		if (ans > Max) {
			Max = ans;
		}if (ans < Min) {
			Min = ans;
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (op[i] > 0) {
			selected[cnt] = i;
			op[i] -= 1;
			dfs(cnt + 1);
			op[i] += 1;
			selected[cnt] = 0;
		}

	}
}
int main() {

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;

		for (int i = 0; i < 4; ++i) {
			cin >> op[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> num[i];
		}
		Max = -1e9; Min = 1e9;
		dfs(0);

		cout << "#" << tc << " " << Max - Min <<"\n";
	}


	return 0;
}