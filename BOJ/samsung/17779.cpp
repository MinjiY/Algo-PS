/* 
    [BOJ] 17779 게리맨더링 2
    https://www.acmicpc.net/problem/17779
*/
#pragma warning (disable: 4996)

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct POINT {
	int y;
	int x;
};
int N;
int map[21][21];
int visit[21][21];
int temp_map[21][21];
int cnt[4];
int ans = 1e9;
vector<POINT> v;
vector<POINT> point;
int start_y, start_x;
void printVisit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printTemp() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << temp_map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void solution(){
	//point[0]= 마름모 위, point[1] == 마름모 오른쪽, point[2] == 마름모 밑, point[3] == 마름모 왼쪽
	//for (int i = 0; i < point.size(); ++i) {
	//	cout << point[i].y << " " << point[i].x << "\n";
	//}
	//printVisit();
	//cout << "\n";

	int arr[6] = { 0};
	for (int i = 0; i < point[3].y; ++i) {
		for (int j = 0; j <= point[0].x; ++j) {
			if (visit[i][j] == 0) {
				temp_map[i][j] = 1;
				//cout << i << " " << j << "\n";
				//printTemp();
				
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i <= point[1].y; ++i) {
		for (int j = N - 1; j > point[0].x; --j) {
			if (visit[i][j] == 0) {
				temp_map[i][j] = 2;
			}
			else {
				break;
			}
		}
	}
	for (int i = N - 1; i > point[1].y; --i) {
		for (int j = N - 1; j >= point[2].x; --j) {
			if (visit[i][j] == 0) {
				temp_map[i][j] = 3;
			}
			else {
				break;
			}
		}
	}
	for (int i = N - 1; i >= point[3].y; --i) {
		for (int j = 0; j < point[2].x; ++j) {
			if (visit[i][j] == 0) {
				temp_map[i][j] = 4;
			}
			else {
				break;
			}
		}
	}
	//구역마다 인구수 저장
	for (int i = 0; i < N ; ++i) {
		for (int j = 0; j < N ; ++j) {
			if (temp_map[i][j] == 1) {
				arr[1] += map[i][j];
			}else if (temp_map[i][j] == 2) {
				arr[2] += map[i][j];
			}else if (temp_map[i][j] == 3) {
				arr[3] += map[i][j];
			}else if (temp_map[i][j] == 4) {
				arr[4] += map[i][j];
			}
			else if(temp_map[i][j] ==0){
				arr[5] += map[i][j];
			}
		}
	}
	sort(arr, arr + 6);
	if (ans> (arr[5] - arr[1])) {
		ans = arr[5]-arr[1];
	}
	memset(temp_map, 0, sizeof(temp_map));
	return;
}
void dfs(int y, int x, int turn) {
	if (start_y == y && start_x == x && turn == 3) {

	//	point.push_back({ y,x });
		solution();
	//	point.pop_back();
		
		return;
	}
	if (y < 0 || x < 0 || y >= N || x >= N)
		return;
	
	visit[y][x] = 1;			
	
	if (turn == 0) {
		cnt[0]++;
		dfs(y+1, x+1, 0);		//오른쪽 아래
		cnt[0]--;
		if (cnt[0] != 0) {
			point.push_back({ y,x });
			cnt[1]++;
			dfs(y+1, x-1, 1);	//왼쪽 아래
			cnt[1]--;
			point.pop_back();
		}
	}
	else if (turn == 1) {
		cnt[1]++;
		dfs(y+1 , x-1 , 1);	//왼쪽 아래
		cnt[1]--;
		if (cnt[1] != 0) {
			point.push_back({ y,x });
			cnt[2]++;
			dfs(y - 1, x - 1, 2);				//왼쪽 위
			cnt[2]--;
			point.pop_back();
		}
	}
	else if (turn == 2) {
		if (cnt[2] == cnt[0]) {					//같으면 꺾음
			point.push_back({ y,x });
			cnt[3]++;
			dfs(y - 1, x + 1, 3);
			cnt[3]--; 
			point.pop_back();
		}
		else if (cnt[2] < cnt[0]) {
			cnt[2]++;
			dfs(y-1, x-1, 2);
			cnt[2]--;
		}
	}
	else {
		cnt[3]++;
		dfs(y - 1, x + 1, 3);
		cnt[3]--;
	}
	visit[y][x] = 0;
	return;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N - 2; ++i) {
		for (int j = 1; j < N - 1; ++j) {
			start_y = i;
			start_x = j;
			point.push_back({ i,j });
			dfs(i, j, 0);
			point.pop_back();
		}
	}
	cout << ans << "\n";

	return 0;
}