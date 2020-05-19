/*
    [BOJ] 11279 최대 힙
    https://www.acmicpc.net/problem/11279
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	priority_queue<int> pq;
	
	int N;
	cin >> N;
	for (int tc = 0; tc < N; ++tc) {
		int x;
		cin >> x;
		
		if (x == 0) {
			if (pq.size()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << "0\n";
			}
		}
		else {
			pq.push(x);
		}
	}


	return 0;
}
