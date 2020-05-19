/*
    [BOJ] 12100 2048(Easy)
    https://www.acmicpc.net/problem/12100
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct INFO {
	int map[21][21];
};

int board[21][21];
int change[21][21];
queue<pair<INFO, int>> q;
int N;
int ans;
void printBoard() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printMap(int map[][21]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void slopeGravity1(int(*board)[21]) {
	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j > 0; --j) {			//뒤에서부터 찾고
			if (board[i][j] == 0) {					//0인 좌표를 찾았으면
				for (int k = j - 1; k >= 0; --k) {
					if (board[i][k] != 0) {
						board[i][j] = board[i][k];
						board[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}
void slopeGravity2(int(*board)[21]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {			//뒤에서부터 찾고
			if (board[i][j] == 0) {					//0인 좌표를 찾았으면
				for (int k = j + 1; k < N; ++k) {
					if (board[i][k] != 0) {
						board[i][j] = board[i][k];
						board[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}
//남쪽으로 
void slopeGravity3(int(*board)[21]) {				//이상함
	for (int j = 0; j < N; ++j) {
		for (int i = N - 1; i > 0; --i) {
			if (board[i][j] == 0) {					//0인 좌표를 찾았으면
				for (int k = i - 1; k >= 0; --k) {
					if (board[k][j] != 0) {
						board[i][j] = board[k][j];
						board[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}
//북쪽으로
void slopeGravity4(int(*board)[21]) {
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N - 1; ++i) {
			if (board[i][j] == 0) {					//0인 좌표를 찾았으면
				for (int k = i + 1; k < N; ++k) {
					if (board[k][j] != 0) {
						board[i][j] = board[k][j];
						board[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}
bool hapche1(int(*board)[21], int(*change)[21]) {
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j > 0; --j) {
			if (board[i][j] == board[i][j - 1]) {
				if (change[i][j] == 0 && change[i][j - 1] == 0) {
					board[i][j] += board[i][j - 1];
					board[i][j - 1] = 0;
					change[i][j] = 1;
					change[i][j - 1] = 1;
					flag = true;
				}
			}
		}
	}
	return flag;
}
bool hapche2(int(*board)[21], int(*change)[21]) {
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (board[i][j] == board[i][j + 1]) {
				if (change[i][j] == 0 && change[i][j + 1] == 0) {
					board[i][j] += board[i][j + 1];
					board[i][j + 1] = 0;
					change[i][j] = 1;
					change[i][j + 1] = 1;
					flag = true;
				}
			}
		}
	}
	return flag;
}
bool hapche3(int(*board)[21], int(*change)[21]) {
	bool flag = false;
	for (int j = 0; j < N; ++j) {
		for (int i = N - 1; i > 0; --i) {
			if (board[i][j] == board[i - 1][j]) {
				if (change[i][j] == 0 && change[i - 1][j] == 0) {
					board[i][j] += board[i - 1][j];
					board[i - 1][j] = 0;
					change[i][j] = 1;
					change[i - 1][j] = 1;
					flag = true;
				}
			}
		}
	}
	return flag;
}
bool hapche4(int(*board)[21], int(*change)[21]) {
	bool flag = false;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N - 2; ++i) {
			if (board[i][j] == board[i + 1][j]) {
				if (change[i][j] == 0 && change[i + 1][j] == 0) {
					board[i][j] += board[i + 1][j];
					board[i + 1][j] = 0;
					change[i][j] = 1;
					change[i + 1][j] = 1;
					flag = true;
				}
			}
		}
	}
	return flag;
}
int calBlock(int(*map)[21]) {
	int maxb = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (maxb < map[i][j]) {
				maxb = map[i][j];
			}
		}
	}
	return maxb;
}
void cpyA(INFO* temp, INFO A) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			temp->map[i][j] = A.map[i][j];
		}
	}
}
void bfs() {
	while (!q.empty()) {
		INFO A = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt >= 5) {
			int maxb = calBlock(A.map);
			if (ans < maxb) {
				ans = maxb;
			}
			continue;
		}

		for (int d = 1; d < 5; ++d) {
			INFO temp = {{0}};
			cpyA(&temp, A);
			memset(change, 0, sizeof(change));
			if (d == 1) {
				slopeGravity1(temp.map);
				if (hapche1(temp.map, change)) {
					slopeGravity1(temp.map);
				}
			}
			else if (d == 2) {
				slopeGravity2(temp.map);
				if (hapche2(temp.map, change)) {
					slopeGravity2(temp.map);
				}
			}
			else if (d == 3) {
				slopeGravity3(temp.map);
				if (hapche3(temp.map, change)) {
					slopeGravity3(temp.map);
				}
			}
			else if (d == 4) {
				slopeGravity4(temp.map);
				if (hapche4(temp.map, change)) {
					slopeGravity4(temp.map);
				}
			}
			q.push(make_pair(temp, cnt + 1));
			memset(change, 0, sizeof(change));
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	INFO temp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			temp.map[i][j] = board[i][j];
		}
	}
	q.push(make_pair(temp, 0));
	bfs();
	cout << ans << "\n";
	return 0;
}