/*
    [BOJ] 17087 숨바꼭질 6
    https://www.acmicpc.net/problem/17087
*/

#include <iostream>
using namespace std;

// 1<= N <= 1e6
// 1<= S <= 1e10
// 1<= Ai <=1e10

long long N, S;		//동생 N명, 수빈이 위치, 
long long A[1000001];
long long MIN = 1e10 + 9999999999;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long ans = 0;
	long long a;
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		A[i] =abs(S - a);	//distance
	}
	if (N == 1) {
		cout << A[0] << "\n";
		return 0;
	}
	ans = gcd(A[0], A[1]);
	for (int i = 2; i < N-1; ++i) {
		ans = gcd(ans, A[i]);
	}
	cout << ans << "\n";


	/*
	//첫번째 시도 : 예제는 다 맞았으나 틀림
	=> 수빈이가 움직일 수 있는 최대거리가 아니라 고정된 보폭임
	for (int i = 0; i < N; ++i) {
		MIN = min(MIN, (abs(S - pose[i])));
	}
	cout << MIN<<"\n";
	*/
	
	return 0;
}