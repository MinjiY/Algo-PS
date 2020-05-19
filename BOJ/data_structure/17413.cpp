/*
    [BOJ] 17413 단어 뒤집기 2
    https://www.acmicpc.net/problem/17413
*/

#include <cstdio>
char str[100010];


void Swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void char_swap(int begin, int end) {
	int length2 = end - begin + 1;
	for (int i = begin; i < (length2 / 2) + begin; ++i) {
		Swap(&str[i], &str[begin+end - i]);
	}
}
int main() {
	int length = 0; 
	int start = 0;
	int flag = 0;
	for (int i = 0; i < 100001; ++i) {
		scanf("%c", &str[i]);
		if (str[i] == '\n') {
			length = i;
			break;
		}
	}
	for(int i = 0; i < length+1; ++i) {
		if (start >i) {
			break;
		}
		if (str[i] == '>') {
			flag = 0;
			start = i + 1;
			continue;
				
		}
		else if (flag == 1) {
			continue;
		}
		if (flag == 0 && i!= 0  ){
			if (str[i] == ' ' || str[i] == '\n'|| str[i]== '<') {
				char_swap(start, i - 1);
				start = i + 1;
			}
		}
		if (str[i] == '<') {
			flag = 1;
			continue;
		}
	}
	for (int i = 0; i<length; ++i) {
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}
