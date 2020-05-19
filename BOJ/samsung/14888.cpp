/*
    [BOJ] 14888 연산자 끼워넣기
    https://www.acmicpc.net/problem/14888
 */
#include <iostream>
using namespace std;

int N;
int arr[12];
//덧셈, 뺄셈, 곱셈, 나눗셈
int op[4];
int selected[12];
int MAX = -1e9;
int MIN = 1e9;
void permutation(int cnt) {
	if (cnt == N - 1) {
		int result = arr[0];
		int indx = 1;
		
		for (int i = 0; i < N - 1; ++i) {
			if (selected[i] == 0) {	//+
				result = result+ arr[indx++];
			}
			else if (selected[i] == 1) {	//-
				result = result - arr[indx++];
			}
			else if (selected[i] == 2) {	//*
				result = result * arr[indx++];
			}
			else if (selected[i] == 3) {	// 나눗셈
				result = result / arr[indx++];
			}
		}
		if (MAX < result) {
			MAX = result ;
		}
		if (MIN > result) {
			MIN = result;
		}

		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (op[i] > 0) {
			selected[cnt] = i;
			op[i] -= 1;
			permutation(cnt + 1);
			op[i] += 1;
			selected[cnt] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}

	permutation(0);

	cout << MAX << "\n" << MIN << "\n";
	return 0;
}

