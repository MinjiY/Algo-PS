/*
    [BOJ] 1158 요세푸스 문제
    https://www.acmicpc.net/problem/1158
*/
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

int N, K;
vector<int> v;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N >> K;

	int num = 0;
	for (int i = 0; i < N; ++i) {
		 q.push(i + 1);
	}

	//int dest_size = q.size();
	while (q.size()) {
		for (int i = 0; i < K; ++i) {
			//dequeue
			num = q.front();
			q.pop();
			if (i == (K - 1)) {
				break;
			}
			//enqueue
			q.push(num);
		}
		v.push_back(num);
	//	dest_size--;
	}
//	v.push_back(num);

	
//	cout <<"num: "<< num<<endl;
	cout << "<";
	for (int i = 0; i < N; ++i) {
		if (i == N - 1) {
			cout << v[i];
		}
		else {
			cout << v[i] << ", ";
		}
	}
	cout <<">"<< endl;
	

	return 0;
}
