/* 
    [BOJ] 11653 소인수분해
    https://www.acmicpc.net/problem/11653
*/

#include <iostream>
using namespace std;

#define MAX 10000001

bool check[MAX];
long long input;

void prime() {
	for (int i = 2; i * i < MAX; ++i) {
		if (!check[i]) {
			for (int j = i * i; j < MAX; j += i) {
				check[j] = 1;
			}
		}
	}
	check[1] = 1;
}

void solution(long long input) {

		for (long long i = 2; i < MAX; ++i) {
			while (!check[i])
			{
				//i

				if (input % i == 0) {
					input = input / i;
					cout << i << "\n";
				}
				else if (input == 1) {
					return;
				}
				else {
					break;
				}
			}
		}
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> input;
	prime();
	solution(input);

	return 0;
}
