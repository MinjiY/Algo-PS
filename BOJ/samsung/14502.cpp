/*
    [BOJ] 14502 연구소
    https://www.acmicpc.net/problem/14502    
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int cnt;
int MAX;
int map[10][10];
int visit[10][10];
int mapVisit[10][10];

int virus[10][10];
 const int dy[] = { 0,0,-1,1 };
const int dx[] = { -1,1,0,0 };
vector<pair<int, int>> v;
void printMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout<<  map[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printVirus() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << virus[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void copy_to_virus() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			virus[i][j] = map[i][j];
		}
	}
}
void numOfsafe() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (virus[i][j] == 0) {
				cnt++;
			}
		}
	}
}

void bfs() {
	copy_to_virus();
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); ++i) {
		visit[v[i].first][v[i].second] = 1;
		q.push(make_pair(v[i].first, v[i].second));
	//	cout << v[i].first << " " << v[i].second << "\n";
	}
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (visit[ny][nx])
				continue;

			if(virus[ny][nx] == 0){
				visit[ny][nx] = 1;
				virus[ny][nx] = 2;
			//	printVirus();
				q.push(make_pair(ny, nx));
			}

		}


	}
	
	numOfsafe();
	if (MAX < cnt) {
	//	printVirus();
		MAX = cnt;
	}
	cnt = 0;
	
	return;
}
void dfs(int cnt,int x) {
	if (cnt == 3) {
		//printMap();
		bfs();
		memset(visit, 0, sizeof(visit));
		return;
	}
	for (int i = 0; i< N; ++i) {
		for (int j = x; j < M; ++j) {
			if (map[i][j] == 0 ) {
				
				map[i][j] = 1;
				dfs(cnt + 1, j);
				map[i][j] = 0;
			}
		}
	}
}
int main() {
//	freopen("14502.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
//	cout << "초기맵\n";
//	printMap();
	dfs(0,0);
//	printMap();
	cout << MAX << "\n";


//	fclose(stdin);
	return 0;
}