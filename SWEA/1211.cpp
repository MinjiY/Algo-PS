/*
    [SWEA] 1211 Ladder2
 */
#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>
#define MAX 100
int map[100][100];
int visit[100][100];
int list[100];
const int dy[] = { 0,0,1 };
const int dx[] = { 1,-1,0 };

int cnt;
int Min = 9991119;

void input() {
	int number;
	cin >> number;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cin >> map[i][j];
		}
	}
}
void printMap() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printVisit() {
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n\n";
}

void dfs(int y, int x) {
	int y2 = y, x2 = x;
	while (y2 <MAX) {
		if (y2 == MAX - 1) {
			Min = min(Min, cnt);
			return;
		}
		for (int i = 0; i < 3; ++i) {
			int ny = y2 + dy[i];
			int nx = x2 + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= MAX || nx >= MAX)
				continue;

			if ( !visit[ny][nx] && map[ny][nx]) {
				visit[ny][nx] = 1;
				y2 = ny;
				x2 = nx;
				cnt++;
				break;
			}				
		}
		
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <=10; ++tc) {
		Min = 9991119;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(list, 0, sizeof(list));

		input();
		//printMap();
		
		for (int i = 0; i < MAX; ++i) {
			if (map[0][i]) {
				visit[0][i] = 1;
				dfs(0, i);
				list[i] = cnt;
				cnt = 0;
				memset(visit, 0, sizeof(visit));
			}
		}
		for (int i = 0; i < MAX; ++i) {
			if (Min == list[i]) {
				cout <<"#"<<tc<<" "<<i<<"\n";
			}
		}
	}
	//fclose(stdin);
	return 0;
}