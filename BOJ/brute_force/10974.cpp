/*
    [BOJ] 10974 모든 순열
    https://www.acmicpc.net/problem/10974
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N , indx;
int arr[8];
int main() {
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	while (indx != -1 ) {
		indx = -1;
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		for (int i = (N - 1); i >0; --i)
		{
			if (arr[i - 1] < arr[i]) {
				indx = i - 1;
				break;
			}
		}

		if (indx == -1) {
			break;
		}

		sort(arr + (indx + 1), arr + N);

		int j = indx + 1;
		for (; arr[j] <= arr[indx]; j++) {}
	
		swap(arr[indx], arr[j]);
	
	}
	return 0;
}