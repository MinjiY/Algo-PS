/*
    [BOJ] 11656 접미사 배열
    https://www.acmicpc.net/problem/11656
 */

#include <algorithm>
#include <iostream>
using namespace std;

string input;
string arr[1001];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> input;
	
	for (int i = 0; i < input.length(); ++i) {	//input
		for (int j = i; j < input.length(); ++j) {
			arr[i].append(1,input[j]);
		}
	}
	
	sort(arr, arr+input.length());
	
	for (int i = 0; i < input.length(); ++i) {
		cout << arr[i]<< "\n";
	}

	return 0;
}
