/*
    [BOJ] 부분수열의 합
    https://www.acmicpc.net/problem/1182
*/
#include <cstdio>

int N, S;
int arr[21];
int main() {

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; ++i) {
		scanf(" %d", &arr[i]);
	}/*
	for (int i = 0; i < N; ++i) {
		printf("%d ", arr[i]);
	}*/

	int result = 0;
	for (int i = 1; i < (1 << N); ++i) {//합을 구할 부분수열의 길이
		int sum = 0;

		for (int j = 0; j < N; ++j) {
			if (i & (1 << j))
				sum += arr[j];
		}

		if (sum == S)
			result++;
	}
	printf("%d\n", result);
	return 0;
}