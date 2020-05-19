/*
    [BOJ] 1057 토너먼트
    https://www.acmicpc.net/problem/1057
*/
#include <iostream>
using namespace std;

int N;
struct INFO {
	int v;
	int indx;
};
INFO check[2];
int arr[100001];
void printArr() {
	for (int i = 1; i <= N; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	int goalL, goalR;
	cin >> goalL >> goalR;
	for (int i = 1; i <= N; ++i) {
		arr[i] = i;
	}
	int ans = 0;
	int cnt = 0;
	int r = 1;
	while (1) {
		for (int i = 1; i <= N; ++i) {
			if (arr[i] > 0) {
				check[cnt].v = arr[i];
				check[cnt].indx = i;

				cnt++;
				if (cnt > 1) {
					cnt = 0;
					
				//	cout << check[0].v << " "<<check[1].v << "\n";
					if (check[0].v == goalL && check[1].v == goalR) {
						ans = r;
						break;
					}
					else if (check[0].v == goalR && check[1].v == goalL) {
						ans = r;
						break;
					}
					else if (check[0].v == goalL || check[0].v == goalR) {
						arr[check[1].indx] = 0;
					}
					else if (check[1].v == goalL || check[1].v == goalR) {
						arr[check[0].indx] = 0;
					}
					else {
						arr[check[1].indx] = 0;
					}
				}
				
			}
		}
		if (cnt > 0) {
			cnt = 0;
		}
		r++;
		if (ans > 0) {
			break;
		}

	}

	cout << ans << "\n";

	return 0;
}