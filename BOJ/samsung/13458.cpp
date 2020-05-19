/*
    [BOJ] 시험 감독
    https://www.acmicpc.net/problem/13458
*/
#include <iostream>
using namespace std;

int N;
int A[1000001];
int B, C;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cin >> B >> C;

	long long cnt = 0;
	

	for (int i = 0; i < N; ++i) {

			A[i] -= B;
			cnt++;
	
		if (A[i] > 0) {
			if ((A[i] % C) == 0) {
				cnt += (A[i] / C);
			}
			else {
				cnt += (A[i] / C) + 1;
			}
		}
	}

	cout << cnt<<"\n";
	return 0;
}