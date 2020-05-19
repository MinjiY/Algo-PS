/*
    [BOJ] 9093 단어뒤집기
    https://www.acmicpc.net/problem/9093
*/
#include <cstdio>
using namespace std;

int T;
char str[1000];

void Swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void char_swap(int begin, int end) {
	//printf("begin: %d , end: %d \n", begin, end);
	int length = (end - begin)+1;
	for (int i = begin; i < (length / 2)+begin; ++i) {
		Swap(&str[i], &str[begin+end - i]);
	}
}

int main() {
	scanf("%d", &T);
	while (getchar() != '\n');

	while (T) {
		int length = 0;
		int start = 0;
		for (int i = 0; i < 1000; ++i) {	//문자열 입력받기 + 문자열길이
			scanf("%c", &str[i]);
			//cin >> str[i];
			if (str[i] == 10) {
				break;
			}
			length++;
		}

		for (int j = 0; ; ++j) {
			//printf("str[%d]: %c\n", j, str[j]);
			if (str[j] == 32 || str[j] == 10) {
				char_swap(start, j - 1);
				start = j + 1;
			}
			if (str[j] == 10) {
				break;
			}
		}
		for (int i = 0; i < length; ++i) {
			printf("%c", str[i]);
		}
        printf("\n");
		T--;
	}
	/*	
	//입력받은거 확인
	for (int i = 0; i < length; ++i) {
		if (str[i] != 32 && str[i] != 10) {
			printf("%c", str[i]);
		}
		else if(str[i] == 32) {				//space
			printf(" ");
		}
		else if (str[i] == 10) {			//enter
			printf("\n");
		}
	}*/
	return 0;
}