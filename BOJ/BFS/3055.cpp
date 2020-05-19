/*
    [BOJ] 3055 탈출
    https://www.acmicpc.net/problem/3055
*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int water;
	int time;
}NODE;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
char map[51][51];
int water[51][51];			//물인지 땅인지 + 시간여부
int dochi[51][51];			//시간여부
int w_visit[51][51];
int d_visit[51][51];

int N, M;
int w_time;
int d_time;
queue<pair<pair<int, int>,pair<int,int>>> q;		//y,x, 물/도치, 시간
//물 = 1, 도치 = 2


bool unsafeSection(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return true;
	}
	return false;
}
void printWater() {
	printf("water print\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", water[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", w_visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printMap() {
	printf("map print\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void printDochi() {
	printf("dochi print\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", dochi[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void bfs() {

	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> temp = q.front();
		q.pop();
//		printf("y: %d x: %d stae: %d time: %d\n",temp.first.first,temp.first.second,temp.second.first,temp.second.second);
		int state = temp.second.first;
		int t = temp.second.second;
		for (int i = 0; i < 4; ++i) {
			int ny = temp.first.first + dy[i];
			int nx = temp.first.second + dx[i];
			
			if (unsafeSection(ny, nx))
				continue;
		
			if (state == 1) {					//물
				if (w_visit[ny][nx])
					continue;

				w_visit[ny][nx] = 1;
				if (map[ny][nx] == 'X' || map[ny][nx] == 'D')
					continue;

				water[ny][nx] = t + 1;
			//	printWater();
				q.push(make_pair(make_pair(ny, nx), make_pair(1, t + 1)));
			}
			else if (state == 2)				//도치
			{
				if (d_visit[ny][nx])
					continue;

				d_visit[ny][nx] = 1;
				//printf("dochi 들어옴 t+1: %d\n",t+1);
				//printf("ny: %d nx: %d water[ny][nx]: %d\n", ny, nx, water[ny][nx]);
				if (map[ny][nx] == 'X')
					continue;
				if (map[ny][nx] == 'D')
				{
					//끝
					printf("%d\n", t + 1);
					return;
				}
				else if (water[ny][nx] > (t+1) || water[ny][nx] ==0 )		//도치보다 물이 1초 더 앞선상황
				{
					dochi[ny][nx] = t + 1;
				//	printDochi();
					q.push(make_pair(make_pair(ny, nx), make_pair(2, t + 1)));
				}
			}
		}
	}
	printf("KAKTUS\n");
}
int main() {
	int NumOfWater = 0;
	int y=0, x=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '*') {
				NumOfWater++;
				w_visit[i][j] = 1;
				q.push(make_pair(make_pair(i, j),make_pair(1 ,w_time)));
			}
			else if (map[i][j] == 'S') {
				y = i; x = j;
			}
		}
	}
	//여기서 물한번돌림

	while (NumOfWater--) {
		pair<pair<int, int>, pair<int, int>> temp = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int ny = temp.first.first+dy[i];
			int nx = temp.first.second+dx[i];
			int state = temp.second.first;
			int t = temp.second.second;
			
			if (unsafeSection(ny, nx))
				continue;
			
			if (map[ny][nx] == 'X' || map[ny][nx] == 'D') 
				continue;
			
			if (w_visit[ny][nx] == 1)
				continue;

			water[ny][nx] = t+1;
			w_visit[ny][nx] = 1;

			q.push(make_pair(make_pair(ny, nx), make_pair(1, t+1)));
		}

	}

	d_visit[y][x] = 1;
	q.push(make_pair(make_pair(y, x), make_pair(2, d_time)));

	bfs();
	return 0;
}