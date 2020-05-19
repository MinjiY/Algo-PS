/*
    [BOJ] 17298 오큰수
    https://www.acmicpc.net/problem/17298
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v(n), ans(n);
	for(int i=0; i<n; i++) cin >> v[i];

	stack<int> stk; stk.push(1e9+7);
	for(int i=n-1; i>=0; i--){
		while(stk.top() <= v[i]) stk.pop();
		if(stk.top() >= 1e9) ans[i] = -1;
		else ans[i] = stk.top();
		stk.push(v[i]);
	}
	for(auto i : ans) cout << i << " ";
}