#include <iostream>
#include <cmath>
using namespace std;

long long A, B, C;
long long pow(long long a, long long b) {
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;

	if (b % 2 > 0)
		return pow(a, b - 1) * a;

	long long half = pow(a, b / 2);
	half %= C;
	return (half * half) % C;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	
	cout << pow(A, B) % C << "\n";
	return 0;
}