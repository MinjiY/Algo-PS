/*
    [BOJ] 10866 덱
    https://www.acmicpc.net/problem/10866
*/
#include <iostream>
#include <deque>
#define endl "\n"
using namespace std;

deque<int> dq;
int N;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N;

	while (N) {
		string command;

		cin >> command;

		if (command == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (command == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (command == "size") {
			cout << dq.size() << endl;
		}
		else if (command == "empty") {
			cout << dq.empty() << endl;
		}
		else if (command == "front") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.front() << endl;
			}
		}
		else if (command == "back") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.back() << endl;
			}
		}
		--N;
	}
	return 0;
}