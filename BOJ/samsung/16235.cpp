/*
    [BOJ] 16235 나무 제테크
    https://www.acmicpc.net/problem/16235
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct {
	vector<int> tree;			//나이
	int yangboon;				//양분
}NODE;
NODE map[11][121];
int A[11][121];
int N, M, K;
const int dy[] = { 0,0,1,-1,1,1,-1,-1 };
const int dx[] = { 1,-1,0,0,1,-1,1,-1 };
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j].tree.size()) {
				for (int k = 0; k < map[i][j].tree.size(); ++k) {
					cout << map[i][j].tree[k] << " ";
				}
			}
			cout << map[i][j].yangboon<< "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void spring() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j].tree.size()) {
				int s = map[i][j].tree.size();
				int dead = 0;
				bool flag = false;
				sort(map[i][j].tree.begin(), map[i][j].tree.end());
				for (int k = 0; k < s; ++k) {
					if (map[i][j].yangboon >= map[i][j].tree[k])
					{
						map[i][j].yangboon -= map[i][j].tree[k];
						map[i][j].tree[k]++;
					//	cout << map[i][j].yangboon << " " << map[i][j].tree[k] << " \n";
					}
					else {
					//	cout << "여기\n";
						dead = k;
						flag = true;
						break;
					}
				}
				if (flag) {
					for (int k = s - 1; k >= dead; --k) {						//여름에 할일
						map[i][j].yangboon += (map[i][j].tree[k] / 2);
						map[i][j].tree.pop_back();
					}
				}
			}
		}
	}
}
void fall() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j].tree.size()) {
				int s = map[i][j].tree.size();
				for (int k = 0; k < s; ++k) {
					if ( ((map[i][j].tree[k]%5) == 0)&& (map[i][j].tree[k]!=0) ) {
						
						for (int dir = 0; dir < 8; ++dir) {
							int ny = i + dy[dir];
							int nx = j + dx[dir];
							if (ny < 0 || nx < 0 || ny >= N || nx >= N)
								continue;
							
							map[ny][nx].tree.push_back(1);
						}
					
					}

				}

			}
		}
	}

}
void winter() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			map[i][j].yangboon += A[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			map[i][j].yangboon = 5;		//초기양분은 5
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, z;
		cin >> y >> x >> z;
		map[y-1][x-1].tree.push_back(z);
	}

	while (K--) {
		spring();
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j].tree.size()) {
				ans += map[i][j].tree.size();
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}