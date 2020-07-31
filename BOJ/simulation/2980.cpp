/*
	[BOJ] 2980 ���ο� ��ȣ��
	https://www.acmicpc.net/problem/2980
*/

#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
int N, L;	//��ȣ�� ����, ������ ����
pair<int, int> arr[1001];	//R,G
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		int d, r, g;
		cin >> d >> r >> g;
		arr[d].first = r;
		arr[d].second = g;
	}

	int t = 1;				//��ü �ð�
	int m = 1;
	while (m < L) {
		if (arr[m].first != 0 && arr[m].second != 0) {
			if ((t % (arr[m].first + arr[m].second)) <= arr[m].first)	//������
			{
				t += (arr[m].first - (t % (arr[m].first + arr[m].second)));
			}
		}
		t++;
		m++;
	}
	cout << t << "\n";
	return 0;
}