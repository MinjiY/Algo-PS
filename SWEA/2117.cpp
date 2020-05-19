/*
    [SWEA] 2117 홈 방범 서비스
    모의 SW 역량테스트
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;				//가로세로, 집이 지불할비용
int map[20][20];
int visit[20][20];
int profit;
int house_max;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };


void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout <<	visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int Company_Benefit(int k) {
	return (k * k) + (k - 1) * (k - 1);
}
void bfs(int y, int x) {
	int house = 0;
	int service = 1;
	pair<int, int> temp;

	queue<pair<int, int>> q;

	visit[y][x] = 1;
	if (map[y][x] == 1) house++;
	q.push(make_pair(y,x));
	
	
	while (q.empty()==0) {
		if (service > (N + 1)) break;
		
		if (house * M - Company_Benefit(service) >=0) {
			house_max = max(house, house_max);
		}
		int s = q.size();

		for (int Qs = 0; Qs < s; ++Qs) {
			temp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int ny = temp.first + dy[i];
				int nx = temp.second + dx[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] == 1)
					continue;

				visit[ny][nx] = 1;
				if (map[ny][nx] == 1) {
					++house;
				}
				q.push(make_pair(ny, nx));
			}
		}
		++service;
	}
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		house_max = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
					memset(visit, 0, sizeof(visit));
					bfs(i, j);
			}
		}
		cout << "#" <<tc<<" "<<house_max<<"\n";
	}
	return 0;
}