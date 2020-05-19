/*
    [SWEA] 1970 쉬운 거스름돈
 */
#include <iostream>
using namespace std;
int T, N;
int main() {
	int units[8] = {50000,10000,5000,1000,500,100,50,10};
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d", &N);
		printf("#%d\n", tc);
		for(int i=0; i<8; i++) {
			int ea = N/units[i];
			N %= units[i];
			printf("%d ", ea);
		}
		printf("\n");
	}
}