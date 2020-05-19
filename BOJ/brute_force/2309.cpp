/*
    [BOJ] 2309 일곱 난쟁이
    https://www.acmicpc.net/problem/2309
 */
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int height[9] = { 0 };
	int sum = 0;
	int a, b;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8-i; j++) {
			if (height[j] > height[j + 1]) {
				swap(height[j], height[j + 1]);
			}
		}
	}
	
	for (int i = 0; i < 9; i++) {
		sum += height[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if ( 100 == sum - (height[i] + height[j])) {
				a = i;
				b = j;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if ((i == a) || (i == b)) {
			continue;
		}
		printf("%d\n", height[i]);
	}


	return 0;
}