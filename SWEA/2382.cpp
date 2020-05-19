/*
    [SWEA] 2382 미생물 격리
    모의 SW 역량테스트
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"
using namespace std;
//상하좌우
const int dy[] = { 0,-1,1,0,0 };
const int dx[] = { 0,0,0,-1,1 };
int T, N, M, K;		//셀, 격리시간, 군집 갯수

typedef struct {
	int num;
	int dir;
}NODE;
typedef struct {
	int y; int x;
	int num;
	int dir;
}MOVE;
NODE map[101][101];
vector<MOVE> move_v;
vector<NODE> temp[101][101];
bool visit_flag[101][101];


bool cmp(NODE p1, NODE p2) {
	if (p1.num > p2.num) {
		return true;
	}
	return false;
}
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%3d %3d  ",map[i][j].num,map[i][j].dir);
			//cout << map[i][j].num << "   " << map[i][j].dir << "    ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void bacteria_move() {	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j].num) {
				int ny = i + dy[map[i][j].dir];
				int nx = j + dx[map[i][j].dir];
				move_v.push_back({ ny,nx,map[i][j].num,map[i][j].dir});
				map[i][j].num = 0;
				map[i][j].dir = 0;
			}
		}
	}
}

void After_move() {
	
	for (int i = 0; i < move_v.size(); ++i) {
	/*	cout << move_v[i].y << " " << move_v[i].x << "\n";
		cout << move_v[i].num << " " << move_v[i].dir << "\n";
		cout << "차례:\n";*/
		int y = move_v[i].y;			//이미 다음칸의 정보가 들어있음
		int x = move_v[i].x ;
		
		if ( y == 0 || x == 0 || y == N - 1 || x == N - 1) {	//약품 칠해진 칸
	//		cout << "1\n";
			map[y][x].num = (move_v[i].num / 2);
			if ((move_v[i].dir % 2) == 1) {
				map[y][x].dir = move_v[i].dir + 1;
			}
			else {
				map[y][x].dir = move_v[i].dir - 1;
			}
		}
		else if (map[y][x].num) {	//거기에 이미 뭐가있어
	//		cout << "2\n";
			if (!visit_flag[y][x]) {
				temp[y][x].push_back({ map[y][x].num, map[y][x].dir });
				visit_flag[y][x] = true;
			}
			temp[y][x].push_back({ move_v[i].num, move_v[i].dir });
		}
		else {						//약품도 없고 뭐가있지도 않아
	//		cout << "3\n";
			map[y][x].num = move_v[i].num;
			map[y][x].dir = move_v[i].dir;
		}
		
	}

	for(int i=0; i<N; ++i){
		for (int j = 0; j < N; ++j) {
			if (temp[i][j].size()) {
				sort(temp[i][j].begin(), temp[i][j].end(), cmp);

				int sum = 0;
				for (int k = 0; k < temp[i][j].size(); ++k) {
					sum += temp[i][j][k].num;
				}
				map[i][j].num = sum;
				map[i][j].dir = temp[i][j][0].dir;
				temp[i][j].clear();
			}
		}
	}


	//printMap();
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (temp[i][j].size()) {
				for (int k = 0; k < temp[i][j].size(); ++k) {
					cout << temp[i][j][k].num << " " << temp[i][j][k].dir<<" ";
				}
			}
		}
	}*/
	move_v.clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(map, 0, sizeof(map));
		move_v.clear();
		cin >> N >> M >> K;
	
		int cnt = 0;
		for (int i = 0; i < K; ++i) {
				int y, x, num, dir;
				cin >> y >> x >> num >> dir;
				map[y][x].num = num;
				map[y][x].dir = dir;
		}
		while (cnt < M) {
			bacteria_move();
			
			After_move();
			memset(visit_flag, 0, sizeof(visit_flag));
			//printMap();
			cnt++;
			
			//	printMap();
				/*for (int i = 0; i < move_v.size(); ++i) {
					cout << "\n";
					cout << move_v[i].y << " " << move_v[i].x << "\n";
					cout << move_v[i].num << " "<< move_v[i].dir<<"\n";
				}*/
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j].num) {
					ans += map[i][j].num;
				}
			}
		}
		cout << "#"<<tc << " " << ans<<"\n";
	}

	return 0;
}