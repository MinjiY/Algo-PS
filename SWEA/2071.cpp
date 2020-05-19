/*
    [SWEA] 2071 평균값 구하기
 */
#include <cstdio>
 
int main(void) {
    int T, Answer, num, sum;
 
    scanf("%d", &T);
 
    for(int t_case = 0; t_case < T; t_case++) {
        sum = 0;
 
        for(int i=0; i<10; i++) {
            scanf("%d", &num);
            sum += num;
        }
 
        Answer = sum/10;
        if(sum%10 >= 5)
            Answer++;
 
        printf("#%d %d\n", t_case+1, Answer);
    }
    
    return 0;
}