/*
	[BOJ] 11279 ÃÖ´ë Èü
	https://www.acmicpc.net/problem/11279
*/
#pragma warning (disable: 4996)

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N = 0;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.size() == 0) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}

	}
	return 0;
}

/*
	[BOJ] 1927 ÃÖ¼Ò Èü


#include <iostream>
#include <functional>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N = 0;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.size() == 0) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}

	}
	return 0;
}
*/