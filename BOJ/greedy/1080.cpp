/*
    [BOJ] 1080 행렬
    https://www.acmicpc.net/problem/1080
*/
#include <cstdio>
using namespace std;

int n, m;
int A[51][51];
int B[51][51];
int cnt;
void flip(int y, int x) {
	cnt++;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (A[y+i][x+j] == 0) A[y+i][x+j] = 1;
			else
				A[y+i][x+j] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %1d", &A[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %1d", &B[i][j]);
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 2; ++j) {
			if (A[i][j] != B[i][j]) {
				flip(i, j);
			}
		}
	}
	
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] != B[i][j]) {
				printf("-1\n");
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag) printf("%d\n", cnt);

	return 0;
}