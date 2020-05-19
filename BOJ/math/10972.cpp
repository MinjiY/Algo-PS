/*
    [BOJ] 10972 다음 순열
    https://www.acmicpc.net/problem/10972
 */
#include <iostream>
#include <algorithm>
using namespace std;

// 7 2 3 6 5 4 1 
int N;
int arr[10001];

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> N;
	
	for(int i=0; i<N; ++i){
		cin >> arr[i];
	}	
	
	// 1. arr[i] > arr[i-1] 를 만족하는 가장 큰 i를 찾음 
	int index =-1;
	for(int i=N; i>0; --i){
		if( arr[i] > arr[i-1] ){
			index = i-1;
			break;
		}
	}
	if(index == -1){
		cout << "-1";
		return 0;
	}
	
	//greater<> : 내림차순
	//less<> : 오름차순 
	sort(arr+(index+1), arr+N);
	
	int j = index+1;
	while( arr[j] <= arr[index] ){
		++j;
	}
	swap(arr[j], arr[index]);
	
	for(int i =0; i<N; ++i){
		cout << arr[i]<<" ";
	}
	return 0;
}