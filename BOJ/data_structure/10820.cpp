/*
    [BOJ] 10820 문자열 분석
    https://www.acmicpc.net/problem/10820
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int cnt[4];
char str[200];
int main() {

	// A: 65 ~ Z: 90
	// a: 97 ~ z: 122
	//소문자 대문자 숫자 공백
	while (cin.getline(str, 200)) {
        memset(cnt,0,sizeof(cnt));
        int length = strlen(str);

		for (int i = 0; i < length; ++i) {
			if (str[i] >= 'A' && str[i] <= 'Z') cnt[1]++;
			else if (str[i] >= 'a' && str[i] <= 'z')cnt[0]++;
			else if (str[i] >= '0' && str[i] <= '9')cnt[2]++;
			else if (str[i] == ' ') cnt[3]++;
		}
		for (int i = 0; i < 4; ++i) {
			printf("%d ", cnt[i]);
		}
		printf("\n");

		//	for (int i = 0; i < length; ++i) {
		//		printf("%c", str[i]);
		//	}
	}
	return 0;
}