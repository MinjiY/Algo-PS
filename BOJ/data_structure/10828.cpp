/*
	[BOJ] 10828 스택
	https://www.acmicpc.net/problem/10828
*/
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
int N;
vector<int> stack;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	
	while (N) {
		string command;
		
		cin >> command;

		if (command == "push") {
			int num = 0;
			cin >> num;
			stack.push_back(num);
		}
		else if (command == "pop") {
			if (stack.size() > 0) {
				cout << stack.back() << endl;
				stack.pop_back();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (command == "top") {
			if (stack.size() > 0) {
				cout << stack.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (command == "size"){
			cout << stack.size() << endl;
		}
		else if (command == "empty") {
			cout << stack.empty() << endl;
		}
		N--;
	}

	return 0;
}