#pragma warning (disable: 4996)
/*
	[BOJ] 6549 ������׷����� ���� ū ���簢��
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
		
		//height�� ��� �Է� �޾ƿ��� h��, width�� �ε��� ��
		long long area = 0;
		for (int i = 0; i < N; ++i) {
			//������ ������� �ʰ�, i��° ���簢���� ���̺��� ���ÿ� ����ִ� �ε����� ���̰� ū ���
			while (!s.empty() && (h[s.top()] >= h[i])) {
				
				long long height = h[s.top()];
				long long width = i;
				s.pop();

				if (!s.empty())
					width = i - s.top()-1;			//stack���� �ε����� ����
				
				if (width * height > area) area = width * height;

			}
			s.push(i);
		}

		//������ ��� �Է¹��� height�� �� ���Ҵµ� ������ ������� ���� ���
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