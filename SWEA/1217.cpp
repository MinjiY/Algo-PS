/*
    [SWEA] 1217 거듭제곱
 */
#include <stdio.h>
int power(int num1,int num2) {
	if (num2 == 1) {
		return num1;
	}
	return num1 * power(num1, (num2 - 1));
}

int main(void) {
		int num1, num2,test_case;
    	for(int i=0; i<10; i++){
			scanf("%d", &test_case);
			scanf("%d %d", &num1, &num2);
	    	printf("#%d %d\n",test_case, power(num1,num2));
        }
	return 0;
}
