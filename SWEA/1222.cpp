/*
    [SWEA] 1222 계산기1
 */
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	int length = 0;
	char str[200] = { 0 };
	int count = 1;
	int result = 0;

	while (count<11) {
		scanf("%d", &length);
		scanf("%s", str);
		result=0;

		for (int i = 0; i < length; i+=2) {
				result += (str[i]-'0');
			}
   
		printf("#%d %d\n", count, result);
		
        count++;
    }
	
	return 0;
}