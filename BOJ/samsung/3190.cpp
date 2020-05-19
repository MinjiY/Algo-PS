/*
    [BOJ] 3190 뱀
    https://www.acmicpc.net/problem/3190
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct INFO {
	int apple;		//자리에 사과가 있으면 1 없으면 0
	int snake;		//몸이면 2
	int dir;
};
INFO map[101][101];
int tail_y, tail_x;
int head_y, head_x;
int dir;
int N;				//보드 크기
int K;				//사과의 갯수
int L;				//방향 변환 횟수

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
//게임 시작시간으로부터 X초가 끝난뒤에 왼쪽 또는 오른쪽으로 방향을 바꾸겠다는 의미
//게임이 몇초에 끝나는지 출력
queue<pair<int, char>> q;

void printSnake() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j].snake << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printApple() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j].apple << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void changeDir(char d) {
	if (dir == 0) {
		if (d == 'L') {
			dir = 3;
		}
		else if (d == 'D') {
			dir = 2;
		}
	}
	else if (dir == 1) {
		if (d == 'L') {
			dir = 2;
		}
		else if (d == 'D') {
			dir = 3;
		}
	}
	else if (dir == 2) {
		if (d == 'L') {
			dir = 0;
		}
		else if (d == 'D') {
			dir = 1;
		}
	}
	else if (dir == 3) {
		if (d == 'L') {
			dir = 1;
		}
		else if (d == 'D') {
			dir = 0;
		}
	}
}
bool safeSection(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)
		return true;
	return false;
}
int main() {
	cin >> N;

	cin >> K;
	for (int i = 0; i < K; ++i) {
		int y, x;
		cin >> y >> x;
		map[y-1][x-1].apple = 1;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) {
		int x;
		char c;
		cin >> x;
		cin >> c;
		q.push(make_pair(x, c));
	}
	map[0][0].snake = 2;
	map[0][0].dir = 0;
	//	printSnake();
	//printApple();

	/*
		ny ,nx 만들어서 거기에 사과있는지 확인하고 꼬리
		초반에는 사과있는지 확인한다음에 0,0에 꼬리대입
		그뒤에는 사과확인한다음에 대입

		while에는 전체 time존재
	*/
	int t = 0;
	head_y = 0, head_x = 0;
	while (1) {
		//printSnake();
		if (t == 0) {
			int ny = head_y + dy[dir];
			int nx = head_x + dx[dir];

			if (map[ny][nx].apple) {
				map[ny][nx].apple = 0;
				map[ny][nx].snake = 2;						        //map[head_y][head_x].snake
				map[head_y][head_x].dir = dir;
				head_y = ny;
				head_x = nx;
			}
			else if (safeSection(ny,nx)) {
				break;
			}
			else {
				map[ny][nx].snake = 2;					        	//map[head_y][head_x].snake
				map[head_y][head_x].dir = dir;
				map[tail_y][tail_x].snake = 0;
				int nny = tail_y + dy[map[tail_y][tail_x].dir];		//꼬리위치 업데이트
				int nnx = tail_x + dx[map[tail_y][tail_x].dir];
				tail_y = nny;
				tail_x = nnx;
				head_y = ny;
				head_x = nx;
			}
		}
		else {
			if (q.size()) {
				if (q.front().first == t) {
					char d = q.front().second;
					changeDir(d);
					q.pop();
				}
			}
			int ny = head_y + dy[dir];
			int nx = head_x + dx[dir];

			if (safeSection(ny,nx)) {			// 벽에 부딪힘
				break;
			}
			else if (map[ny][nx].snake == 2) {				//몸통에 부딪힘
				break;
			}
			else {
				if (map[ny][nx].apple) {
					map[ny][nx].apple = 0;
					map[ny][nx].snake = 2;					//움직이고	map[head_y][head_x].snake
					map[head_y][head_x].dir = dir;
					head_y = ny;							//head 위치 업데이트
					head_x = nx;
															//꼬리는 그대로 꼬리
				}
				else {
					map[ny][nx].snake = 2;					//움직이고 map[head_y][head_x].snake
					map[head_y][head_x].dir = dir;
					map[tail_y][tail_x].snake = 0;
					int nny = tail_y + dy[map[tail_y][tail_x].dir];							//꼬리위치 업데이트
					int nnx = tail_x + dx[map[tail_y][tail_x].dir];
					tail_y = nny;
					tail_x = nnx;
					head_y = ny;							//head 위치 업데이트
					head_x = nx;

				}
			}
		}
		t++;
	}
	cout << t+1<<"\n";
	return 0;
}