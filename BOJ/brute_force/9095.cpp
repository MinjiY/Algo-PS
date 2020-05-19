/*
    [BOJ] 9095 1,2,3 더하기
    https://www.acmicpc.net/problem/9095
*/
//재귀
#include <iostream>
using namespace std;

int T,input;
int cnt;
void recursive(int sum) {
	if (sum == input) {
		cnt++;
		return;
	}if (sum > input) {
		return;
	}
	recursive(sum + 1);
	recursive(sum + 2);
	recursive(sum + 3);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> input;
		
		cnt = 0;
		recursive(0);
		cout << cnt<<"\n";

	}
	return 0;
}

/* 
//dp
#include <cstdio>

int main(){
	int T;
	scanf("%d ", &T);

	int input[100];
	int ans[100];
	int num [50];
	
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	
	for(int i=4; i<11;i++){
		ans[i] = ans[i-1]+ans[i-2]+ans[i-3];
	}
	for(int i = 0; i<T;i++){
		scanf("%d", &num[i]);
		
	}	
	for(int i=0; i<T; i++){
		//int temp = num[i];
		printf("%d\n", ans[num[i]]);
	}
	return 0;
}


*/