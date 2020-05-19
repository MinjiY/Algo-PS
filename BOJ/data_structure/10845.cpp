/*
    [BOJ] 10845 큐
    https://www.acmicpc.net/problem/10845
*/
#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;
queue<int> q;
int N;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N;
	while (N) {
		string command;
		cin >> command;
		//while (getchar() != '\n');
		int num = 0;
		if (command == "push") {
			cin >> num;
			q.push(num);

		}
		else if (command == "pop") {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				int num = q.front();
				q.pop();
				cout << num << endl;
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			if (q.size() > 0) {
				cout << q.empty() << endl;
			}
			else {
				cout << "1" << endl;
			}
		}
		else if (command == "front") {
			if (q.size() > 0) {
				cout << q.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (command == "back") {
			if (q.size() > 0) {
				cout << q.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		--N;
	}

	return 0;
}