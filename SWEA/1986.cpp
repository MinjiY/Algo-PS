/*
    [SWEA] 1986 지그재그 숫자
 */
#include <iostream>
using namespace std;

int N;
int T;
int arr[11];

int main(){
	cin >> T;
	
	int test_case;
	for(test_case=0; test_case<T; ++test_case){
		cin >> N;
		
		int sum=0;
		for(int i=1; i<=N; ++i){
			if (i%2 == 1){
				sum += i;
			}
			else if(i%2 == 0){
				sum -=i;
			}
		}

		cout <<"#"<<test_case+1<<" "<< sum <<"\n";
	}
	return 0;
}