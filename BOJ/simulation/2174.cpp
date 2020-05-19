/*
    [BOJ] 2174 로봇 시뮬레이션
    https://www.acmicpc.net/problem/2174
*/
#include <iostream>
#include <vector>
#define n(N,y) N - y + 1
using namespace std;
typedef struct {
	int num;
	int dir;
}ROBOT;
int N, M;
int R, K;
ROBOT map[101][101];
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
vector<pair<int, int>> loc;
void printMap() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cout << map[i][j].num << " " << map[i][j].dir << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main() {
	cin >> M >> N;
	cin >> R >> K;		//로봇, 명령
	loc.push_back(make_pair(0,0));		//1번부터 시작해서 
	bool flag =false;
	for (int i = 0; i < R; ++i) {
		int y, x; char dir;
		cin >> x >> y;
		cin >> dir;
		
		map[n(N,y)][x].num = i + 1;
		loc.push_back(make_pair(n(N, y), x));
		if (dir == 'E') {
			map[n(N, y)][x].dir = 0;
		}else if (dir == 'W') {
			map[n(N, y)][x].dir = 1;
		}else if (dir == 'S') {
			map[n(N, y)][x].dir = 2;
		}else if (dir == 'N') {
			map[n(N, y)][x].dir = 3;
		}
		
	}
	
	for (int command = 0;command < K; ++command) {
		int num, cnt;
		char dir;
		cin >> num;
		cin >> dir;
		cin >> cnt;
		
		if (dir == 'L') {
			cnt = cnt % 4;

			while (cnt--) {
			//	printMap();
				int d = map[loc[num].first][loc[num].second].dir;
				if (d == 0) {
					map[loc[num].first][loc[num].second].dir = 3;
				}
				else if (d == 1) {
					map[loc[num].first][loc[num].second].dir = 2;
				}
				else if (d == 2) {
					map[loc[num].first][loc[num].second].dir = 0;
				}
				else if (d == 3) {
					map[loc[num].first][loc[num].second].dir = 1;
				}
			}
		}else if (dir == 'R') {
			cnt = cnt % 4;
			while (cnt--) {
			//	printMap();
				int d = map[loc[num].first][loc[num].second].dir;
				if (d == 0) {
					map[loc[num].first][loc[num].second].dir = 2;
				}
				else if (d == 1) {
					map[loc[num].first][loc[num].second].dir = 3;
				}
				else if (d == 2) {
					map[loc[num].first][loc[num].second].dir = 1;
				}
				else if (d == 3) {
					map[loc[num].first][loc[num].second].dir = 0;
				}
			}
		}else if (dir == 'F') {
			while (cnt--) {
			//	printMap();
				int dir = map[loc[num].first][loc[num].second].dir;

				int ny = loc[num].first + dy[dir];
				int nx = loc[num].second + dx[dir];

			//	cout << ny << " " << nx << "\n";
				if (map[ny][nx].num) {
					flag = true;
					cout << "Robot " << num << " crashes into robot " << map[ny][nx].num << "\n";
					++command;
					while (command < K) {
						int num, cnt;
						char dir;
						cin >> num;
						cin >> dir;
						cin >> cnt;
						++command;
					}
					break;
				}
				else if (ny <= 0 || nx <= 0 || ny > N || nx > M) {
					flag = true;
					cout << "Robot " << num << " crashes into the wall\n";
					++command;
					while (command < K) {
						int num, cnt;
						char dir;
						cin >> num;
						cin >> dir;
						cin >> cnt;
						++command;
					}
					break;
				}
				else {
					map[ny][nx].num = num;
					map[ny][nx].dir = dir;

					map[loc[num].first][loc[num].second].dir = 0;
					map[loc[num].first][loc[num].second].num = 0;
					loc[num].first = ny;
					loc[num].second = nx;
				}
 			}
		}
	}
	if (!flag) {
		cout << "OK\n";
	}

	return 0;
}