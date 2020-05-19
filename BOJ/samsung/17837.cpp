/*
    [BOJ] 17837 새로운 게임2
    https://www.acmicpc.net/problem/17837
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

typedef struct {
	int number;
	int dir;
}NODE;
typedef struct {
	int y, x, number, dir;
}MOVE;
const int dy[] = { 0,0,0,-1,1 };
const int dx[] = { 0 ,1,-1,0,0 };

int N, K;
bool flag;
int map[15][15];
vector<NODE> unit[15][15];


void printUnit() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (unit[i][j].size()) {
				cout << "y : " << i << " x: " << j << "\n";
				for (int k = 0; k < unit[i][j].size(); ++k) {
					cout << unit[i][j][k].number << " " << unit[i][j][k].dir << endl;
				}
				cout << "\n";
			}
		}
	}
}

//arr = y, x, number, dir
int find_info(int number,int *arr) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (unit[i][j].size()) {
				for (int k = 0; k < unit[i][j].size(); ++k) {
					if (unit[i][j][k].number == number) {
						*(arr + 0) = i;
						*(arr + 1) = j;
						*(arr + 2) = number;
						*(arr + 3) = unit[i][j][k].dir;
						return k;
					}
				}
			}
		}
	}
}
int find_index(int y, int x, int number) {
	for (int k = 0; k < unit[y][x].size(); ++k) {
		if (unit[y][x][k].number == number)
		{
			return k;
		}
	}
}
bool counting_unit() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (unit[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}
void unit_move(){
	for (int z = 1; z <= K; ++z) {
	//	cout<< z<<"번 차례"<<endl;
		int arr[4] = { 0, };
		int indx = find_info(z, arr);
		int dir = arr[3];
		int y = arr[0];
		int x = arr[1];
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		int number = arr[2];


		if (ny == 0 || nx == 0 || ny > N || nx > N) {
			if ((unit[y][x][indx].dir % 2) == 1) {
				unit[y][x][indx].dir++;
			}
			else if ((unit[y][x][indx].dir % 2) == 0) {
				unit[y][x][indx].dir--;
			}
			//재정의
			int dir = unit[y][x][indx].dir;
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			
			/*if (map[ny][nx] == 2) {

			}
			else if (ny <= 0 || nx <= 0 || ny > N || nx > N) {
			
			}
			else{
				vector<NODE>::iterator it = unit[y][x].begin() + indx;
				unit[ny][nx].insert(unit[ny][nx].end(), it, unit[y][x].end());
				unit[y][x].erase(it, unit[y][x].end());
			}*/
			if (map[ny][nx] == 2) {
				continue;
			}
			else if (ny == 0 || nx == 0 || ny > N || nx > N) {
				continue;
			}
			else if (map[ny][nx] == 1) {
				reverse(unit[y][x].begin() + indx, unit[y][x].end());
				vector<NODE>::iterator it = unit[y][x].begin() + indx;
				unit[ny][nx].insert(unit[ny][nx].end(), it, unit[y][x].end());
				unit[y][x].erase(it, unit[y][x].end());
			}
			else {
				vector<NODE>::iterator it = unit[y][x].begin() + indx;
				unit[ny][nx].insert(unit[ny][nx].end(), it, unit[y][x].end());
				unit[y][x].erase(it, unit[y][x].end());
			}
		}
		else {
			if (map[ny][nx] == 0) {		//흰색
				unit[ny][nx].insert(unit[ny][nx].end(), unit[y][x].begin() + indx, unit[y][x].end());
				unit[y][x].erase(unit[y][x].begin() + indx, unit[y][x].end());
				
			}
			else if (map[ny][nx] == 1) { // 빨간색

				reverse(unit[y][x].begin() + indx, unit[y][x].end());
				unit[ny][nx].insert(unit[ny][nx].end(), unit[y][x].begin() + indx, unit[y][x].end());
				unit[y][x].erase(unit[y][x].begin() + indx, unit[y][x].end());

			}
			else if (map[ny][nx] == 2) { //파란색
				if ((unit[y][x][indx].dir % 2) == 1) {
					unit[y][x][indx].dir++;
				}
				else if ((unit[y][x][indx].dir % 2) == 0) {
					unit[y][x][indx].dir--;
				}
				//재정의
				int dir = unit[y][x][indx].dir;
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (map[ny][nx] == 2) {
					continue;
				}
				else if (ny == 0 || nx == 0 || ny > N || nx > N) {
					continue;
				}
				else if (map[ny][nx] == 1) {
					reverse(unit[y][x].begin() + indx, unit[y][x].end());
					vector<NODE>::iterator it = unit[y][x].begin() + indx;
					unit[ny][nx].insert(unit[ny][nx].end(), it, unit[y][x].end());
					unit[y][x].erase(it, unit[y][x].end());
				}else {
					vector<NODE>::iterator it = unit[y][x].begin() + indx;
					unit[ny][nx].insert(unit[ny][nx].end(), it, unit[y][x].end());
					unit[y][x].erase(it, unit[y][x].end());
					/*cout << "ny: " << ny << " nx: " << nx << endl;
					for (int k = 0; k < unit[ny][nx].size(); ++k) {
						cout << unit[ny][nx][k].number << " " << unit[ny][nx][k].dir << "\n";
					}*/
					//printUnit();
				}
			}
			/*cout <<"cnt: "<< cnt << endl;
			printUnit();*/
			if (counting_unit()) {
				flag = true;
				return;
			}
		}
	}
}

int main() {
	//freopen("sample.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= K; ++i) {
		int y, x, dir;
		cin >> y >> x >> dir;
		unit[y][x].push_back({ i,dir });

	}
	int cnt = 1;
	while (cnt <=1000) {
		//cout <<"cnt: "<<  cnt << "\n";
		unit_move();
		if (flag) {
			cout << cnt << "\n";
			return 0;
		}
		cnt++;
	}
	cout << "-1" << "\n";
	//fclose(stdin);
	return 0;
}