/*
    [BOJ] 17822 원판 돌리기
    https://www.acmicpc.net/problem/17822
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int circle[60][60];
int visit[60][60];
int N, M, T;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
vector<pair<int, int>> v;

void printMap() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << circle[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> T;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> circle[i][j];
		}
	}
	while (T--) {
//		cout << "초기\n";
//		printMap();
		v.clear();
		memset(visit, 0, sizeof(visit));
		bool flag = false;
		int x, d, k;
		cin >> x >> d >> k;
		
		for (int i = 1; i <= N; ++i) {
			
			if ((i % x) == 0) {
				int r = 0;
				if (d == 0) {
					while (r < k) {
						int temp = circle[i][M - 1];
						for (int j = M - 1; j > 0; j--) {
							circle[i][j] = circle[i][j - 1];
						}
						circle[i][0] = temp;
						r++;
					}
				}
				else {
					while (r < k) {
						int temp = circle[i][0];
						for (int j = 0; j < M-1; ++j) {
							circle[i][j] = circle[i][j + 1];
						}
					//	circle[i][M-1] = temp;
						circle[i][(M-1)] = temp;

						r++;
					}

				}
			}
		}
//		cout << "회전후\n";
//		printMap();
		//인접하면서 수가 같은거 찾기
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (circle[i][j] != 0) {
					visit[i][j] = 1;
					for (int k = 0; k < 4; ++k) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (ny<1 || ny>N)
							continue;
						
						if (nx < 0) {
							nx = M - 1;
						}
						else if (nx >= M) {
							nx = 0;
						}
						if (circle[i][j] == circle[ny][nx]) {
							flag = true;
							if (visit[ny][nx] == 0) {
								v.push_back(make_pair(i, j));
								v.push_back(make_pair(ny, nx));
							}
						}
					}
				}
			}
		}
		if (!flag) {
			int sum = 0;
			int cnt = 0;
			int avg = 0;
			for (int i = 1; i <= N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (circle[i][j] != 0) {
						sum += circle[i][j];
						cnt++;
					}
				}
			}
			if (cnt != 0) {
				//			cout << "sum: " << sum << " cnt: " << cnt << "\n";
				avg = sum / cnt;
				//			cout << "avg: " << avg << "\n";
				for (int i = 1; i <= N; ++i) {
					for (int j = 0; j < M; ++j) {
						if (circle[i][j] != 0) {
							if (circle[i][j] < avg) {
								circle[i][j] += 1;
							}
							else if (circle[i][j] > avg) {
								circle[i][j] -= 1;
							}
							else if (circle[i][j] == avg) {
								if ((sum % cnt) == 0) {

								}
								else {
									circle[i][j] += 1;
								}
							}
						}
					}
				}
				//			cout << "평균후\n";
				//			printMap();
			}
		}
		else {
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			for (int i = 0; i < v.size(); ++i) {
				int y = v[i].first;
				int x = v[i].second;
				circle[y][x] = 0;
			}
//			cout << "인접한거 지운후\n";
//			printMap();
		}
	}
//	printMap();
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += circle[i][j];
		}
	}
	cout << ans << "\n";


	return 0;
}