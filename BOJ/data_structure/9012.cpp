/*
    [BOJ] 9012 괄호
    https://www.acmicpc.net/problem/9012
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define endl "\n"
int T;
vector<int> stack;
string str;

void solution() {
	int length = str.size();
	char input;
	for (int i = 0; i < str.size(); ++i) {
		input = str[i];

		if (input == '(') {
			stack.push_back(input);
		}
		else if (input == ')') {
			if (stack.size() > 0 && stack.back() == '(') {
				stack.pop_back();
			}
			else if (stack.size() == 0) {
				printf("NO\n");
				return;
			}
		}
	}

	if (stack.size() == 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return;
}


int main() {
	scanf("%d", &T);

	while (T) {
		stack.clear();
		cin >> str; 
		solution();
		T--;
	}
	return 0;
}