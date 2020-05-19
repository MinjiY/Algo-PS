/*
    [BOJ] 2743 단어 길이 재기
    https://www.acmicpc.net/problem/2743
 */
#include <cstdio>
int main() {
	char str[101] = { 0, };
	int length = 0;
	for (int i = 0; i<101 ; ++i) {
		scanf("%c", &str[i]);
		if (str[i] == '\n') {
			length = i;
			break;
		}
	}
	printf("%d", length );
	return 0;
}