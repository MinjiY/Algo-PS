/*
    [BOJ] 15658 연산자 끼워넣기(2)
    https://www.acmicpc.net/problem/15658
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

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
		for (int i = 0; i < 4; ++i) {
			cin >> op[i];
		}
		
		Max = -1e9; Min = 1e9;
		dfs(0);

		cout << Max<<"\n"<< Min << "\n";
	

	return 0;
}
