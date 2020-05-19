/*
    [SWEA] 1989 초심자의 회문 검사
 */
#include <stdio.h>
#include <string.h>
int n;

int main(){

	int i;
	int j=1;
	char arr[10]={0};
	int flag[10] ={0};
	scanf("%d",&n);
	while(j<=n){
		scanf("%s", arr);
		int len = strlen(arr);		
		for(i= 0; i<len; ++i){
			if(arr[i] != arr[len-1-i])
				flag[j] = 1;
		}		
		++j;			
	}
	
	for(i=1; i<j; ++i){
		printf("#%d %d\n",i, !flag[i]);
		
	}
	return 0;
}