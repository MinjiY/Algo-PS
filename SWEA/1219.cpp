/*
    [SWEA] 1219 길찾기
 */
#include <stdio.h>
#include <memory.h>
#include <iostream>

using namespace std;
int result;
int a[100];
int b[100];
int length;

void dfs(int now) {
	if (a[now] == 99 || b[now] == 99) {
		result = 1;
		return;
	}
	else {
		if (a[now] != -1) 
            dfs(a[now]);
		if (b[now] != -1)
			dfs(b[now]);
	}
}

int main(void) {

	int test_case;
	int count = 10;
	int num1, num2;


	while (count--) {
		fill(a, a + 100, -1);
		fill(b, b + 100, -1);
		result = 0;
		scanf("%d %d", &test_case, &length);
		for (int i = 0; i < length; i++) {
			scanf("%d %d", &num1, &num2);
			if (a[num1] == -1)
				a[num1] = num2;
			else
				b[num1] = num2;
		}
		dfs(0);

		printf("#%d %d\n", test_case, result);


	}
	return 0;
}
