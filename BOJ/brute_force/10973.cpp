/*
    [BOJ] 10973 이전 순열
    https://www.acmicpc.net/problem/10973
*/
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
	int N, indx = 0;
	scanf("%d", &N);

	int arr[10000];

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	if (N == 1) {
		printf("-1");
		return 0;
	}

	indx = N - 1;
	while (arr[indx - 1] < arr[indx]) {
		indx--;
		if (indx == 0)
			break;
	}
	if (indx == 0) {
		printf("-1");
		return 0;
	}
	
	
	
	int j = 0;
	for (j = N - 1; (arr[j] > arr[indx-1]); --j);


	swap(arr[indx-1], arr[j]);
	sort(&arr[indx], &arr[N],greater<int>());

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
