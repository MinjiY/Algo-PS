#pragma warning (disable: 4996)
/*
	[BOJ] 6549 히스토그램에서 가장 큰 직사각형
	https://www.acmicpc.net/problem/6549
*/

#include <iostream>
#include <stack>
using namespace std;

stack<long long> s;
long long N;
int h[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; ++i) {
			cin >> h[i];
		}
		
		//height의 경우 입력 받아오는 h값, width는 인덱스 차
		long long area = 0;
		for (int i = 0; i < N; ++i) {
			//스택이 비어있지 않고, i번째 직사각형의 높이보다 스택에 들어있는 인덱스의 높이가 큰 경우
			while (!s.empty() && (h[s.top()] >= h[i])) {
				
				long long height = h[s.top()];
				long long width = i;
				s.pop();

				if (!s.empty())
					width = i - s.top()-1;			//stack에는 인덱스로 들어갔음
				
				if (width * height > area) area = width * height;

			}
			s.push(i);
		}

		//위에서 모든 입력받은 height를 다 돌았는데 스택이 비어있지 않은 경우
		while (!s.empty()) {
			long long height = h[s.top()];
			long long width = N;
			s.pop();
			if (!s.empty()) width = N - s.top() - 1;
			if (width * height > area) area = width * height;
		}
		cout << area << "\n";
	}

	return 0;
}