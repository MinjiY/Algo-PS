/*
    [BOJ] 15649 N과 M(1) 
    https://www.acmicpc.net/problem/15649
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;	// 1<= M <= N <= 8 
vector <int> list;
bool visit[8];

void permutation(int cnt) {
	if ( cnt == M ) {
		for (int i = 0; i < M; i++) {
			cout << list[i]+1 <<" ";
		}
		cout<<"\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			list.push_back(i);
			permutation(cnt + 1);
			list.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	// N과 M , N이 range , M이 출력 갯수
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> N >> M;

	permutation(0);

	return 0;
}