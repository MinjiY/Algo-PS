/*
    [BOJ] 14501 퇴사
    https://www.acmicpc.net/problem/14501
 */
#include <iostream>

using namespace std;
int list[1000];
int price[1000];
int MAX;
int N;

void dfs(int indx, int cnt) {
	if (indx == N) {
		if (list[indx] == 1) {
			cnt += price[indx];			
		}
		if (MAX < cnt) {
			MAX = cnt;
		}
		return;
	}
	if (indx > N) {
		if (MAX < cnt) {
			MAX = cnt;
		}
		return;
	}
	if(indx + list[indx] <= N+1) 
		dfs(indx + list[indx], cnt + price[indx]);
	if (indx + 1 <= N + 1)
		dfs(indx + 1, cnt);

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> list[i] >> price[i];
	}
//	for (int i = 0; i < N; ++i) {
//		cout<< list[i] <<" "<< price[i]<<"\n";
//	}
	for (int i = 1; i <= N; ++i) {
		dfs(i, 0);
	}
	cout << MAX<<"\n";

	return 0;
}
