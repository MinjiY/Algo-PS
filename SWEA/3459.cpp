/*
    [SWEA] 3459 승자 예측하기
 */
#include <stdio.h>
#include <iostream>
 
using namespace std;
 
char *winnerStr[2] = {"Bob", "Alice"};
 
int main(void) {
    int T;
    long int N;
    bool turn;
 
    scanf("%d", &T);
 
    for(int t_case=1; t_case<=T; t_case++) {
        scanf("%ld", &N);
 
        turn = TURN_ALICE;
 
        long int sub = 1;
 
        while(N > 0) {
            N -= sub;
            
            if(turn) {
                sub *= 4;
            }
            turn = !turn;
        }
 
        printf("#%d %s\n", t_case, winnerStr[(int)turn]);
    }
 
    return 0;
}

