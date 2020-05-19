/*
    [BOJ] 16927 배열 돌리기 2
    https://www.acmicpc.net/problem/16927
*/
#include <iostream>
using namespace std;

int N, M; 
long long K;
int map[301][301];
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	int T = 0;
	if (N > M) {
		T = M / 2;
	}
	else {
		T = N / 2;
	}
	int k = 0;
	
	int temp = 0;

	while (k < T) {
		temp = K % ((N - (2 * k) - 1) * 2 + (M - (2 * k) - 1) * 2);
		int R = 0;
		while (R<temp) {
		
		
		
		
			int temp = map[0 + k][0 + k];

			for (int j = 0 + k; j < M - 1 - k; ++j) {
				map[0 + k][j] = map[0 + k][j + 1];
			}

			for (int i = 0 + k; i < N - 1 - k; ++i) {
				map[i][M - 1 - k] = map[i + 1][M - 1 - k];
			}

			for (int j = M - 1 - k; j > 0 + k; --j) {
				map[N - 1 - k][j] = map[N - 1 - k][j - 1];
			}
			//마지막
			for (int i = N - 1 - k; i > 1 + k; --i) {
				map[i][0 + k] = map[i - 1][0 + k];
			}

			map[1 + k][0 + k] = temp;

			//	printMap();

			R++;
		}
		
		k++;
	}
	printMap();

	return 0;
}